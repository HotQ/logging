#include "logging.h"

void initLog(){
	logger->setLevel(logging::level::NOTSET);
	logger->addHandler(streamHandler);

	auto handle = logging::Singleton<logging::FileHandler>::getInstance();
	char pathBuffer[4096]{};
	tm tm; short ms;
	logger->timestamp(tm,ms);
	strftime(pathBuffer,4096,"./log/%Y-%m-%d.log",&tm);
	printf("path %s\n",pathBuffer);
	handle->setPath(pathBuffer,"a");

	logger->addHandler(handle);
}
int main() {
	initLog();

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
