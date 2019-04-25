#ifndef LOGGING_H
#define LOGGING_H

#include "Logger.h"
namespace logging {

//#define log(message, ...) logX(logging::level::WARN, message, ##__VA_ARGS__)
#define info(message, ...) logger->info( __FILE__, __LINE__, __FUNCTION__, message, ##__VA_ARGS__)
#define warn(message, ...) logger->warn( __FILE__, __LINE__, __FUNCTION__, message, ##__VA_ARGS__)
#define fatal(message, ...) logger->fatal( __FILE__, __LINE__, __FUNCTION__, message, ##__VA_ARGS__)
#define error(message, ...) logger->error( __FILE__, __LINE__, __FUNCTION__, message, ##__VA_ARGS__)
#define debug(message, ...) logger->debug( __FILE__, __LINE__, __FUNCTION__, message, ##__VA_ARGS__)
#define notset(message, ...) logger->notset( __FILE__, __LINE__, __FUNCTION__, message, ##__VA_ARGS__)

#define logger (logging::Logger::getInstance())

} // namespace logging
#endif // !LOGGING_H
