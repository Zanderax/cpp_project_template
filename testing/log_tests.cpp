#include "../logger.cpp"

#include <string>

TEST( LogTest, LogString )  
{
	//Setup
	testing::internal::CaptureStdout();
	Logger logger;
	std::string msg = "LogMsg";

	//Run Test
	logger.log( msg );

	//Assert
	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - " + msg + "\n";

	ASSERT_EQ( expected, actual );
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
	std::string actual = testing::internal::GetCapturedStdout();
	
	std::time_t currTime = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&currTime));
	time.pop_back();

	std::string expected = time + " - " + msg + "\n";

	ASSERT_EQ( expected, actual );
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
