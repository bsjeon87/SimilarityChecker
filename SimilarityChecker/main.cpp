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

TEST_F(SimilarityCheckerFixture, alpha1) {
	EXPECT_EQ(40, similarityChecker.getAlphaScore("AABC", "BCA"));
}

TEST_F(SimilarityCheckerFixture, alpha2) {
	EXPECT_EQ(24, similarityChecker.getAlphaScore("AABCE", "KBCA"));
}

TEST_F(SimilarityCheckerFixture, alpha3) {
	EXPECT_EQ(24, similarityChecker.getAlphaScore("KBCA", "AABCE"));
}

TEST_F(SimilarityCheckerFixture, alpha4) {
	EXPECT_EQ(0, similarityChecker.getAlphaScore("A", "BB"));
}

TEST_F(SimilarityCheckerFixture, length1)
{
	EXPECT_EQ(60, similarityChecker.getLengthScore("abab", "bbbb"));
}

TEST_F(SimilarityCheckerFixture, length2)
{
	EXPECT_EQ(0, similarityChecker.getLengthScore("abab", "bb"));
}

TEST_F(SimilarityCheckerFixture, length3)
{
	EXPECT_EQ(0, similarityChecker.getLengthScore("ab", "bbbb"));
}

TEST_F(SimilarityCheckerFixture, length4)
{
	EXPECT_EQ(30, similarityChecker.getLengthScore("ab", "bbb"));
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}