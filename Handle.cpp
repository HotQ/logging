#include "Handle.h"
namespace logging
{
	void logging::Handle::setLevel(logging::level levelno) {
		level = levelno;
	}

	void logging::Handle::setFormatter() {}

	void logging::Handle::addFilter() {}

	void logging::Handle::removeFilter() {}

	StreamHandler::StreamHandler() : stream(stderr) {}
	StreamHandler::StreamHandler(FILE *stream) : stream(stream) {}

	FILE *StreamHandler::setStream(FILE *stream) {
		return this->stream == stream ? nullptr : (this->stream = stream);
	}

	void StreamHandler::handle(const char *record) {
		fprintf(stream, "%s", record);
	}

} // namespace logging