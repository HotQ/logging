#include "Logger.h"

#define log(info) logging::Logger::getInstance()->logNow(logging::level::WARN, __FILE__, __LINE__, __FUNCTION__, info)

int main() {
	using namespace std;

	log("\"here is the 1st test log\"");
	log("\"here is the 2rd test log\"");
	log("\"here is the 3rd test log\"");

	return 0;
}
