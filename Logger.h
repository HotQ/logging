#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

#include "Singleton.h"
#include "Fig.h"
#include "Handle.h"
namespace logging {

	class Logger {
		logging::level level;
		std::vector<std::shared_ptr<Handle>> handles;

		void vlog(logging::level level, const char *file, int lineNo, const char *func, const char *message, va_list args);
	public:
		static std::shared_ptr<Logger> getInstance();
		Logger();

		void timestamp(struct tm & tm, short & milliseconds);

		void info(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void warn(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void fatal(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void error(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void debug(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);
		void notset(const char *file, int lineNo, const char *func, const char *message = nullptr, ...);

		void setLevel(logging::level levelname);
		void addHandler(std::shared_ptr<Handle> const &handle);
		void removeHandler();
		void addFilter();
		void removeFilter();
	};

} // namespace logging
#endif // !LOGGER_H
