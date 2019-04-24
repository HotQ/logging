#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <chrono>
#include <ctime>

#include "Singleton.h"

namespace logging {

	enum level {
		FATAL = 50,
		ERROR = 40,
		WARN = 30,
		INFO = 20,
		DEBUG = 10,
		NOTSET = 10
	};

#ifdef _WIN32
#define localtime_c(tm,now_c) localtime_s(&tm, &now_c)
#else
#define localtime_c(tm,now_c) localtime_r(&now_c,&tm)
#endif 

	class Logger {
	public:
		static std::shared_ptr<Logger> getInstance();
		void timestamp(const char *format, char *buffer, size_t &milliseconds);
		void logNow(int level, const char *file, int lineNo, const char *func, const char *info = nullptr);
	};
} // namespace logging

#endif // !LOGGER_H
