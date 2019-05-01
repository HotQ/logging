#ifndef FORMATTER_H
#define FORMATTER_H

#include "Fig.h"
namespace logging {

	class Formatter {
		static const char *default_time_format;
		static const char *default_msec_format;
		
		void *fmt = nullptr;
		void *datefmt = nullptr;
		char style = '%';

	public:
		void format(char * buffer, size_t const bufferCount, struct Record record);
		void formatTime();
	};

}// namespace logging
#endif // !FORMATTER_H
