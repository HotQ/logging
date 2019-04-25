#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <stdarg.h>

#include "Singleton.h"
#include "Fig.h"
#include "Handle.h"
namespace logging {

#ifdef _WIN32
#define localtime_c(tm,now_c) localtime_s(&tm, &now_c)
#else
#define localtime_c(tm,now_c) localtime_r(&now_c,&tm)
#endif 

	class Logger {
		logging::level level;
		std::shared_ptr<Handle> handle;

		void vlog(int level, const char *file, int lineNo, const char *func, const char *message, va_list args);
	public:
		static std::shared_ptr<Logger> getInstance();
		Logger();

		void timestamp(const char *format, char *buffer, size_t &milliseconds);

		void info(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void warn(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void fatal(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void error(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void debug(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void notset(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);

		void setLevel(logging::level levelname);
		void addHandler(std::shared_ptr<Handle> handle);
		void removeHandler();
		void addFilter();
		void removeFilter();
	};
} // namespace logging

#endif // !LOGGER_H
