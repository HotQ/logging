#include "Formatter.h"
#include <stdio.h>
namespace logging {

	const char *Formatter::default_time_format = "%Y-%m-%d %H:%M:%S";
	const char *Formatter::default_msec_format = "%s.%03d";

	void logging::Formatter::format(char * buffer, size_t const bufferCount, struct Record record)
	{
		char tmBuffer[20]{};
		strftime(tmBuffer, 20, Formatter::default_time_format, &record.tm);

		size_t flen = snprintf(buffer, bufferCount, "%s.%03hd %s %s:% 3d %s() : %s", tmBuffer, record.ms, lvl2str(record.level), record.file, record.lineNo, record.func, record.msg.get());

		if (flen < bufferCount)
			flen += snprintf(buffer + flen, bufferCount - flen, "\n");
	}
} // namespace logging
