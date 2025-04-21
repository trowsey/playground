#include <stdio.h>
#include <gtest/gtest.h>

int main (int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


namespace playground::tests {
	TEST(PlaygroundTests, TestHelloWorld)
	{
		printf("Hello, World!/n");
		ASSERT_EQ(0, 0) << "Test failed";
	}
}
