#ifndef FIG_H
#define FIG_H

#include <ctime>
#include <stdarg.h>
#include <memory>
namespace logging {

#define LOGBUFFERCOUNT 4096
#define MSGBUFFERCOUNT 4006
#define lvl2str(lvl) (lvl > 25 ? (lvl == level::FATAL ? "[FATAL] " : (lvl == level::WARN ? "[WARN]  " : "[ERROR] ")) \
							   : (lvl == level::DEBUG ? "[DEBUG] " : (lvl == level::INFO ? "[INFO]  " : "[NOTSET]")))

	enum level {
		FATAL = 50,
		ERROR = 40,
		WARN = 30,
		INFO = 20,
		DEBUG = 10,
		NOTSET = 0
	};

	struct Record {
		level level;
		short ms;
		struct tm tm;
		const char * file;
		int lineNo;
		const char * func;
		std::shared_ptr<char> msg;
		Record(logging::level level, struct tm tm, short ms, const char * file, int lineNo, const char * func, std::shared_ptr<char> msg) :
			level(level), ms(ms), tm(tm), file(file), lineNo(lineNo), func(func), msg(msg) {}
	};

} // namespace logging

#endif // !FIG_H