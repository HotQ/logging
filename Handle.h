#ifndef HANDLE_H
#define HANDLE_H

#include <stdio.h>

#include "Fig.h"
namespace logging {

	class Handle {
		logging::level level;
	public:
		void setLevel(logging::level levelno);
		void setFormatter();
		void addFilter();
		void removeFilter();

		virtual void handle(const char * record) = 0;
		virtual ~Handle() {};
	};

	class StreamHandler : public Handle {
		FILE* stream;
	public:
		StreamHandler();
		StreamHandler(FILE* stream);
		FILE* setStream(FILE* stream);
		virtual void handle(const char * record) override;

		virtual ~StreamHandler() {};
	};

} // namespace logging
#endif // !HANDLE_H
