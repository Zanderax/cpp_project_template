#ifndef LOG_H
#define LOG_H

#include <string>
#include <map>

class Logger
{
public:
	enum Severity
	{
		Error,
		Info,
		Warning,
		Hack,
		Debug
	};

	void log( const char * msg );
	void log( std::string msg );

	void log( const char * msg, Logger::Severity severity );
	void log( std::string msg, Logger::Severity severity );

private:
	const std::map<Logger::Severity, std::string> severityToString
	{
		{Logger::Error, "Error"},
		{Logger::Info, "Info"},
		{Logger::Warning, "Warning"},
		{Logger::Hack, "Hack"},
		{Logger::Debug, "Debug"}
	};
};

#endif
