#include "logger.hpp"

#include <iostream>
#include <ctime>

void Logger::log( const char * msg )
{
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();
	std::cout << time << " - " << msg << std::endl;
}

void Logger::log( std::string msg )
{
	log( msg.c_str() );
}
