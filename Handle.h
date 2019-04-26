#ifndef HANDLE_H
#define HANDLE_H

#include <stdio.h>
#include "Fig.h"
#include "Formatter.h"
namespace logging {

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

		virtual void _handle(struct Record record) = 0;
		virtual ~Handle() {};
	};

	class StreamHandler : public Handle {
		FILE* stream;
	public:
		StreamHandler();
		StreamHandler(FILE* stream);
		FILE* setStream(FILE* stream);

		virtual void _handle(struct Record record)override;
		virtual ~StreamHandler() {};
	};

} // namespace logging
#endif // !HANDLE_H
