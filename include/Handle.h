#ifndef HANDLE_H
#define HANDLE_H

#include <stdio.h>
#include "Fig.h"
#include "Formatter.h"
namespace logging {
#ifdef _WIN32
#define fopenX(fp,filename,mode) fopen_s(&fp,filename,mode)
#else
#define fopenX(fp,filename,mode) fp = fopen(filename,mode)
#endif 
	class Handle {
	protected:
		logging::level level;
		std::shared_ptr<logging::Formatter> fmter = nullptr;
	public:
		void setLevel(logging::level levelno);
		void setFormatter(std::shared_ptr<logging::Formatter> const &fmter);
		void addFilter();
		void removeFilter();
		void handle(struct Record const & record);

		virtual void emit(struct Record record) = 0;
		virtual ~Handle() {};
	};

	class StreamHandler : public Handle {
	protected:
		FILE* stream;
	public:
		StreamHandler();
		StreamHandler(FILE* stream);
		FILE* setStream(FILE* stream);

		virtual void emit(struct Record record)override;
		virtual ~StreamHandler() {};
	};

	class FileHandler : public StreamHandler {
		class FilePtr{
		public:
			FILE* file;
			FilePtr(const char * filename, const char * mode ){
				fopenX(file,filename,mode);
			}
			FILE *operator ->(){
				return file;
			}
			~FilePtr(){
				fclose(file);
			}
		};

		std::shared_ptr<FilePtr> file = nullptr;
	public:
		FileHandler();
		void setPath(const char * filename, const char * mode );
		void close();

		virtual ~FileHandler() {};
	};

} // namespace logging
#endif // !HANDLE_H
