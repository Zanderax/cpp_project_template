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

void Logger::log( const char * msg, Logger::Severity severity )
{
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();
	auto severityString = severityToString.at( severity );
	std::cout << time << " - [" << severityString << "] - " << msg << std::endl;
}

void Logger::log( std::string msg, Logger::Severity severity )
{
	log( msg.c_str(), severity );
}
