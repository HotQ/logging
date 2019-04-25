#include "Logger.h"
namespace logging {

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

	void logging::Logger::logNow(int level, const char * file, int lineNo, const char * func, const char * info, ...) {
		char buffer[20];
		size_t milliseconds;
		timestamp("%Y-%m-%d %H:%M:%S", buffer, milliseconds);
		printf("%s.%03lu %s %s:% 3d %s() : ", buffer, milliseconds, lvl2str(level), file, lineNo, func);
		if(info != nullptr){
			va_list args;
			va_start(args, info);
			vprintf(info, args);
			va_end(args);
		}
		printf("\n");
	}
} // namespace logging
