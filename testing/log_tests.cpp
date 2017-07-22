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

	ASSERT_EQ( actual, expected );
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

	ASSERT_EQ( actual, expected );
}
