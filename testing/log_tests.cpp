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
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ( output, msg + "\n" );

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
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ( output, msg + "\n" );
}
