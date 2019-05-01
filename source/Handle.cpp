#include "Handle.h"
namespace logging
{
	void logging::Handle::setLevel(logging::level levelno) {
		level = levelno;
	}

	void logging::Handle::setFormatter(std::shared_ptr<logging::Formatter> const &fmter) {
		this->fmter = fmter;
	}

	void logging::Handle::addFilter() {}

	void logging::Handle::removeFilter() {}

	void Handle::handle(Record const & record)
	{
		if (record.level >= this->level) {
			if (fmter == nullptr)
				fmter = std::make_shared<logging::Formatter>();
			this->emit(record);
		}
	}

	StreamHandler::StreamHandler() : stream(stderr) {}
	StreamHandler::StreamHandler(FILE *stream) : stream(stream) {}

	FILE *StreamHandler::setStream(FILE *stream) {
		return this->stream == stream ? nullptr : (this->stream = stream);
	}
	void StreamHandler::emit(Record record)
	{
		char logBuffer[LOGBUFFERCOUNT]{};
		fmter->format(logBuffer, LOGBUFFERCOUNT, record);
		fprintf(stream, "%s", logBuffer);
	}

	FileHandler::FileHandler() {}
	void FileHandler::setPath(const char * filename, const char * mode ){
		this->file = std::make_shared<FilePtr>(filename,mode);
		stream = this->file.get()->file;
	}
	
	
} // namespace logging
