#include "gmock/gmock.h"
#include "similarityChecker.cpp"
#include <string>
using namespace testing;
using namespace std;

TEST(lengthChecker, length1)
{
	SimilarityChecker similarityChecker;
	string inputA = "abab";
	string inputB = "bbbb";

	EXPECT_EQ(60, similarityChecker.getLengthScore(inputA, inputB));
}

TEST(lengthChecker, length2)
{
	SimilarityChecker similarityChecker;
	string inputA = "abab";
	string inputB = "bb";

	EXPECT_EQ(0, similarityChecker.getLengthScore(inputA, inputB));
}


int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}