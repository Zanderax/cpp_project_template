#include "logger.hpp"

#include <iostream>
#include <ctime>
#include <fstream>

Logger::Logger( void )
{
	output = Logger::Output::STDOUT;
}

Logger::Logger( Logger::Output outputIn )
{
	output = outputIn;
	if(outputIn == Logger::Output::FILE)
	{
		output = Logger::Output::STDOUT;
		log( "Logger cannot be set to file output without a file path. "
			"Defaulting to stdout",
			Logger::Severity::Error );
	}
}

Logger::Logger( Logger::Output outputIn, std::string outputFileIn )
{
	if( outputIn != Logger::Output::FILE )
	{
		log( "Initalizing Logger with a file name but output type is"
			" not set to FILE",
			Logger::Severity::Warning );
	}
	output = outputIn;
	outputFile = outputFileIn;
}

void Logger::log( const char * msg )
{
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	switch( output )
	{
		case Logger::Output::STDOUT:
			std::cout << time << " - " << msg << std::endl;
			break;
		case Logger::Output::STDERR:
			std::cerr << time << " - " << msg << std::endl;
			break;
		case Logger::Output::FILE:
			std::ofstream file(outputFile);
			file << time << " - " << msg << std::endl;
			file.close();
			break;	
	}
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
	
	switch( output )
	{
		case Logger::Output::STDOUT:
			std::cout << time << " - [" << severityString << "] - " << msg << std::endl;
			break;
		case Logger::Output::STDERR:
			std::cerr << time << " - [" << severityString << "] - " << msg << std::endl;
			break;
		case Logger::Output::FILE:
			std::ofstream file(outputFile);
			file << time << " - [" << severityString << "] - " << msg << std::endl;
			file.close();
			break;	
	}
}

void Logger::log( std::string msg, Logger::Severity severity )
{
	log( msg.c_str(), severity );
}
