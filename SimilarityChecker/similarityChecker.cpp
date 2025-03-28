
#include <string>

using std::string;

class SimilarityChecker {
public:
	int getLengthScore(string inputA, string inputB)
	{
		if (inputA.length() > inputB.length())
			return (1 - (inputA.length() - inputB.length()) / inputB.length()) * 60;

		return 60;
	}
};