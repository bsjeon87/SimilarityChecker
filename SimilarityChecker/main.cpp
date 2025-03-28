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
	EXPECT_EQ(40, similarityChecker.getScore("AABC", "BCA"));
}

TEST_F(SimilarityCheckerFixture, alpha2) {
	EXPECT_EQ(24, similarityChecker.getScore("AABCE", "KBCA"));
}

TEST_F(SimilarityCheckerFixture, alpha44) {
	EXPECT_EQ(0, similarityChecker.getScore("A", "BB"));
}

TEST_F(SimilarityCheckerFixture, alpha3) {
	EXPECT_EQ(24, similarityChecker.getScore("KBCA", "AABCE"));
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}