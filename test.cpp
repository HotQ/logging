#include "Logger.h"

#define log(info, ...) logging::Logger::getInstance()->logNow(logging::level::WARN, __FILE__, __LINE__, __FUNCTION__, info, ##__VA_ARGS__)

int main() {
	using namespace std;

	log("\"here is the 1st test log with %d arg\"",1);
	log("\"here is the 2rd test log with %d %s\"",3,"char");
	log("\"here is the 3rd test log\"");

	return 0;
}
