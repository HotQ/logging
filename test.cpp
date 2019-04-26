#include "logging.h"

int main() {
	// using namespace std;

	logger->setLevel(logging::level::NOTSET);
	logger->addHandler(streamHandler);
	auto handle = logging::Singleton<logging::FileHandler>::getInstance();
	handle->setPath("./20190426.log","a");
	logger->addHandler(handle);
	const char *strStderr= "stderr",
			   *strStdout= "stdout";
				
	notset("\"%s : here is the 1st test log with %p\"", strStderr,NULL);
	info("\"%s : here is the 1st test log with %d arg\"", strStderr,1);
	debug("\"%s : here is the 2rd test log with %d %s\"", strStderr,3, "char");
	streamHandler->setStream(stdout);
	warn("\"%s : here is the 3rd test log with a fatal flag\"",strStdout);
	error("\"%s : here is the 4rd test log with a error flag\"",strStdout);
	return 0;
}
