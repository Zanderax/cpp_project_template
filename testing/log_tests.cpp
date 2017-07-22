#include "../logger.cpp"

#include <string>
#include <fstream>

void checkSimpleLogOutput( std::string msg )
{
	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - " + msg + "\n";

	ASSERT_EQ( expected, actual );
}

TEST( LogTest, LogString )  
{
	//Setup
	testing::internal::CaptureStdout();
	Logger logger;
	std::string msg = "LogMsg";

	//Run Test
	logger.log( msg );

	//Assert
	checkSimpleLogOutput( msg );
}

TEST( LogTest, LogChar )  
{
	//Setup
	testing::internal::CaptureStdout();
	Logger logger;
	std::string msg = "LogMsg";

	//Run Test
	logger.log( msg.c_str() );

	//Assert
	checkSimpleLogOutput( msg );	
}

void runLogSeverityTest( Logger::Severity severity, std::string severityString )
{

	//Setup
	testing::internal::CaptureStdout();
	Logger logger;
	std::string msg = "LogMsg";

	//Run Test
	logger.log( msg.c_str(), severity );

	//Assert
	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - [" + severityString + "] - " + msg + "\n";

	ASSERT_EQ( expected, actual );
}

TEST( LogTest, LogSeverityError )
{
	runLogSeverityTest( Logger::Severity::Error, "Error" );
}

TEST( LogTest, LogSeverityWarning )
{
	runLogSeverityTest( Logger::Severity::Warning, "Warning" );
}

TEST( LogTest, LogSeverityInfo )
{
	runLogSeverityTest( Logger::Severity::Info, "Info" );
}

TEST( LogTest, LogSeverityHack )
{
	runLogSeverityTest( Logger::Severity::Hack, "Hack" );
}

TEST( LogTest, LogSeverityDebug )
{
	runLogSeverityTest( Logger::Severity::Debug, "Debug" );
}

TEST( LogTest, LoggerDefaultToSTDOUT )
{
	//Setup
	Logger logger;

	//Assert
	ASSERT_EQ( logger.getOutput(), Logger::Output::STDOUT );
}

TEST( LogTest, LoggerInitalizedToSTDERR )
{
	//Setup
	Logger logger(Logger::Output::STDERR);

	//Assert
	ASSERT_EQ( logger.getOutput(), Logger::Output::STDERR );
}


TEST( LogTest, LogToSTDERR )
{
	//Setup
	testing::internal::CaptureStderr();

	Logger logger(Logger::Output::STDERR);

	//Assert

	auto msg = "Info log to STDERR"; 

	logger.log(msg, Logger::Severity::Info);
	
	std::string actual = testing::internal::GetCapturedStderr();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - [Info] - " + msg + "\n";
	
	//Assert
	ASSERT_EQ( logger.getOutput(), Logger::Output::STDERR );
	
	ASSERT_EQ( expected, actual );
}


TEST( LogTest, LoggerInitalizedToFileWithoutFileName )
{
	//Setup
	testing::internal::CaptureStdout();
	Logger logger(Logger::Output::FILE);

	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	auto msg = "Logger cannot be set to file output without a file path. "
			"Defaulting to stdout";

	std::string expected = time + " - [Error] - " + msg + "\n";

	//Assert
	ASSERT_EQ( logger.getOutput(), Logger::Output::STDOUT );
	ASSERT_EQ( expected, actual );
}

TEST( LogTest, LoggerInitalizedToFile )
{
	//Setup
	auto fileName = "file.log";
	Logger logger(Logger::Output::FILE, fileName );

	//Assert
	ASSERT_EQ( logger.getOutput(), Logger::Output::FILE );
	ASSERT_EQ( logger.getOutputFile(), fileName );
}

TEST( LogTest, LogToFile )
{
	//Setup
	auto fileName = "file.log";
	Logger logger(Logger::Output::FILE, fileName );

	//Assert

	auto msg = "Info log to file.log"; 

	logger.log(msg, Logger::Severity::Info);
	
	std::ifstream file;
	file.open(fileName);

	std::string actual;
	std::getline(file, actual);
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - [Info] - " + msg;
	
	//Assert
	ASSERT_EQ( logger.getOutput(), Logger::Output::FILE );
	ASSERT_EQ( logger.getOutputFile(), fileName );
	ASSERT_EQ( expected, actual );
}
