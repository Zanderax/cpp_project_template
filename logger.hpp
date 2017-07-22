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

	enum Output
	{
		STDOUT,
		STDERR,
		FILE
	};

	Logger();
	Logger( Logger::Output output );
	Logger( Logger::Output output, std::string fileName );

	Logger::Output getOutput() { return output; };
	std::string getOutputFile() { return outputFile; };

	void log( const char * msg );
	void log( std::string msg );

	void log( const char * msg, Logger::Severity severity );
	void log( std::string msg, Logger::Severity severity );

private:
	Logger::Output output;
	std::string outputFile;
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
