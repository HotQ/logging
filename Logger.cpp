#include "Logger.h"
namespace logging {

#define logBufferLen 4096
#define lvl2str(lvl) (lvl > 25 ? (lvl == level::FATAL ? "[FATAL]" : (lvl == level::WARN ? "[WARN]" : "[ERROR]")) \
							   : (lvl == level::DEBUG ? "[DEBUG]" : (lvl == level::INFO ? "[INFO]" : "[NOTSET]")))

	std::shared_ptr<Logger> logging::Logger::getInstance() {
		return logging::Singleton<Logger>::getInstance();
	}

	void logging::Logger::timestamp(const char * format, char * buffer, size_t & milliseconds) {
		std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		milliseconds = now.time_since_epoch().count() % 1000;
		struct tm  tm;
		localtime_c(tm, now_c);
		strftime(buffer, 20, format, &tm);
	}

	void logging::Logger::logNow(int level, const char * file, int lineNo, const char * func, const char * message, ...) {
		char timeBuffer[20]{},
			logBuffer[logBufferLen]{};
		size_t milliseconds;
		timestamp("%Y-%m-%d %H:%M:%S", timeBuffer, milliseconds);

		size_t flen = snprintf(logBuffer, logBufferLen, "%s.%03lu %s %s:% 3d %s() : ", timeBuffer, milliseconds, lvl2str(level), file, lineNo, func);
		if (message != nullptr){
			va_list args;
			va_start(args, message);
			flen += vsnprintf(logBuffer + flen, logBufferLen - flen, message, args);
			va_end(args);
		}
		if (flen < logBufferLen)
			flen += snprintf(logBuffer + flen, logBufferLen - flen, "\n");
		printf("%s", logBuffer);
	}
} // namespace logging
