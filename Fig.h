#ifndef FIG_H
#define FIG_H
namespace logging {
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

} // namespace logging

#endif // !FIG_H