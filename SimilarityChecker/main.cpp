#include "gmock/gmock.h"
#include "similarityChecker.cpp"
#include <string>
using namespace testing;
using namespace std;

class SimilarityCheckerFixture : public Test
{
public:
	SimilarityChecker similarityChecker;
};

TEST_F(SimilarityCheckerFixture, length1)
{
	EXPECT_EQ(60, similarityChecker.getScore("abab", "bbbb"));
}

TEST_F(SimilarityCheckerFixture, length2)
{
	EXPECT_EQ(0, similarityChecker.getScore("abab", "bb"));
}

TEST_F(SimilarityCheckerFixture, length3)
{
	EXPECT_EQ(0, similarityChecker.getScore("ab", "bbbb"));
}

TEST_F(SimilarityCheckerFixture, length4)
{
	EXPECT_EQ(30, similarityChecker.getScore("ab", "bbb"));
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}