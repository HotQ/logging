#include "Logger.h"
namespace logging {

#define logBufferLen 4096
#define lvl2str(lvl) (lvl > 25 ? (lvl == level::FATAL ? "[FATAL]" : (lvl == level::WARN ? "[WARN]" : "[ERROR]")) \
							   : (lvl == level::DEBUG ? "[DEBUG]" : (lvl == level::INFO ? "[INFO]" : "[NOTSET]")))

	std::shared_ptr<Logger> Logger::getInstance() {
		return Singleton<Logger>::getInstance();
	}

	Logger::Logger():level(level::WARN){}

	void Logger::timestamp(const char * format, char * buffer, size_t & milliseconds) {
		std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		milliseconds = now.time_since_epoch().count() % 1000;
		struct tm  tm;
		localtime_c(tm, now_c);
		strftime(buffer, 20, format, &tm);
	}

	void Logger::vlog(int level, const char * file, int lineNo, const char * func, const char * message, va_list args) {
		char timeBuffer[20]{},
			logBuffer[logBufferLen]{};
		size_t milliseconds;
		timestamp("%Y-%m-%d %H:%M:%S", timeBuffer, milliseconds);

		size_t flen = snprintf(logBuffer, logBufferLen, "%s.%03lu %s %s:% 3d %s() : ", timeBuffer, milliseconds, lvl2str(level), file, lineNo, func);
		if (message != nullptr){
			flen += vsnprintf(logBuffer + flen, logBufferLen - flen, message, args);
		}
		if (flen < logBufferLen)
			flen += snprintf(logBuffer + flen, logBufferLen - flen, "\n");
		printf("%s", logBuffer);
	}

	void Logger::info(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if(level>level::INFO) return;
		va_list args;
		va_start(args, message);
		vlog(level::INFO, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::warn(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if(level>level::WARN) return;
		va_list args;
		va_start(args, message);
		vlog(level::WARN, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::fatal(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if(level>level::FATAL) return;
		va_list args;
		va_start(args, message);
		vlog(level::FATAL, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::error(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if(level>level::ERROR) return;
		va_list args;
		va_start(args, message);
		vlog(level::ERROR, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::debug(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if(level>level::DEBUG) return;
		va_list args;
		va_start(args, message);
		vlog(level::DEBUG, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::notset(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if(level>level::NOTSET) return;
		va_list args;
		va_start(args, message);
		vlog(level::NOTSET, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::setLevel(logging::level levelname){
		level = levelname;
	}

} // namespace logging
