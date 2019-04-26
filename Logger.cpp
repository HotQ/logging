#include "Logger.h"
namespace logging {

#ifdef _WIN32
#define localtime_c(tm,now_c) localtime_s(&tm, &now_c)
#else
#define localtime_c(tm,now_c) localtime_r(&now_c, &tm)
#endif 

	std::shared_ptr<Logger> Logger::getInstance() {
		return Singleton<Logger>::getInstance();
	}

	Logger::Logger() :level(level::WARN) {
		handle = std::make_shared<StreamHandler>(stdout);
	}

	void Logger::timestamp(struct tm & tm, short & milliseconds) {
		std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		milliseconds = now.time_since_epoch().count() % 1000;
		localtime_c(tm, now_c);
	}

	void Logger::vlog(logging::level level, const char * file, int lineNo, const char * func, const char * message, va_list args) {
		struct tm tm;
		short milliseconds;
		timestamp(tm, milliseconds);
		std::shared_ptr<char> msg(new char[MSGBUFFERCOUNT]);
		if (message != nullptr)
			vsnprintf(msg.get(), MSGBUFFERCOUNT, message, args);
		Record record(level, tm, milliseconds, file, lineNo, func, msg);
		handle->handle(record);
	}

	void Logger::info(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if (level > level::INFO) return;
		va_list args;
		va_start(args, message);
		vlog(level::INFO, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::warn(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if (level > level::WARN) return;
		va_list args;
		va_start(args, message);
		vlog(level::WARN, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::fatal(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if (level > level::FATAL) return;
		va_list args;
		va_start(args, message);
		vlog(level::FATAL, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::error(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if (level > level::ERROR) return;
		va_list args;
		va_start(args, message);
		vlog(level::ERROR, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::debug(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if (level > level::DEBUG) return;
		va_list args;
		va_start(args, message);
		vlog(level::DEBUG, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::notset(const char * file, int lineNo, const char * func, const char * message, ...)
	{
		if (level > level::NOTSET) return;
		va_list args;
		va_start(args, message);
		vlog(level::NOTSET, file, lineNo, func, message, args);
		va_end(args);
	}

	void Logger::setLevel(logging::level levelname) {
		level = levelname;
	}

	void Logger::addHandler(std::shared_ptr<Handle> handle)
	{
		this->handle = handle;
	}

	void Logger::removeHandler()
	{
	}

	void Logger::addFilter()
	{
	}

	void Logger::removeFilter()
	{
	}

} // namespace logging
