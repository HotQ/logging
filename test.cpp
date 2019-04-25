#include "Logger.h"
#define log(message, ...) logX(logging::level::WARN, message, ##__VA_ARGS__)
#define info(message, ...) logX(logging::level::INFO, message, ##__VA_ARGS__)
#define warn(message, ...) logX(logging::level::WARN, message, ##__VA_ARGS__)
#define fatal(message, ...) logX(logging::level::FATAL, message, ##__VA_ARGS__)
#define error(message, ...) logX(logging::level::ERROR, message, ##__VA_ARGS__)
#define debug(message, ...) logX(logging::level::DEBUG, message, ##__VA_ARGS__)
#define notset(message, ...) logX(logging::level::NOTSET, message, ##__VA_ARGS__)

#define logger (logging::Logger::getInstance())

#define logX(level,message, ...) logger->logNow(level, __FILE__, __LINE__, __FUNCTION__, message, ##__VA_ARGS__)

int main() {
	using namespace std;

	info("\"here is the 1st test log with %d arg\"",1);
	debug("\"here is the 2rd test log with %d %s\"",3,"char");
	fatal("\"here is the 3rd test log with a fatal flag\"");
	error("\"here is the 4rd test log with a error flag\"");

	return 0;
}
