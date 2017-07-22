#include "logger.hpp"

#include <string>


int main(void)
{
	Logger logger;
	std::string logMsg = "Log!";
	logger.log( logMsg );
	return 0; 
}
