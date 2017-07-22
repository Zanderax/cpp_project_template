#include "logger.hpp"

#include <iostream>

void Logger::log( const char * msg )
{
	std::cout << msg << std::endl;
}

void Logger::log( std::string msg )
{
	log( msg.c_str() );
}

int Logger::test()
{
	return 4;
}
