#include "gmock/gmock.h"
#include "similarityChecker.cpp"
#include <string>
using namespace testing;
using namespace std;

class SimilarityCheckerFixture : public Test
{
public:
	SimilarityChecker similarityChecker;
	string inputA;
	string inputB;
};

TEST_F(SimilarityCheckerFixture, length1)
{
	inputA = "abab";
	inputB = "bbbb";

	EXPECT_EQ(60, similarityChecker.getLengthScore(inputA, inputB));
}

TEST_F(SimilarityCheckerFixture, length2)
{
	inputA = "abab";
	inputB = "bb";

	EXPECT_EQ(0, similarityChecker.getLengthScore(inputA, inputB));
}

TEST_F(SimilarityCheckerFixture, length3)
{
	inputA = "ab";
	inputB = "bbbb";

	EXPECT_EQ(0, similarityChecker.getLengthScore(inputA, inputB));
}

TEST_F(SimilarityCheckerFixture, length4)
{
	inputA = "ab";
	inputB = "bbb";

	EXPECT_EQ(30, similarityChecker.getLengthScore(inputA, inputB));
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}