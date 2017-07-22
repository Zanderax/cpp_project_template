#ifndef LOG_H
#define LOG_H

#include <string>

class Logger
{
public:
	void log( const char * msg );
	void log( std::string msg );
};

#endif
