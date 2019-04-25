#include "logging.h"

int main() {
	// using namespace std;

	notset("\"here is the 1st test log with %p\"",NULL);
	info("\"here is the 1st test log with %d arg\"",1);
	debug("\"here is the 2rd test log with %d %s\"",3,"char");
	warn("\"here is the 3rd test log with a fatal flag\"");
	error("\"here is the 4rd test log with a error flag\"");
	logger->setLevel(logging::level::NOTSET);

	notset("\"===================\"");
	info("\"here is the 1st test log with %d arg\"",1);
	debug("\"here is the 2rd test log with %d %s\"",3,"char");
	warn("\"here is the 3rd test log with a fatal flag\"");
	error("\"here is the 4rd test log with a error flag\"");
	return 0;
}
