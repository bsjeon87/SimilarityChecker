
#include <string>

using std::string;

class SimilarityChecker {
public:
	int getLengthScore(string inputA, string inputB)
	{
		const static int MAX_LENGTH_SCORE = 60;
		const int inputALen = inputA.length();
		const int inputBLen = inputB.length();

		if (inputALen > inputBLen) {
			return (1 - (inputALen - inputBLen)) / inputBLen * MAX_LENGTH_SCORE;
		}
		else if (inputALen < inputBLen) {
			return (1 - (inputBLen - inputALen)) / inputALen * MAX_LENGTH_SCORE;
		}

		return MAX_LENGTH_SCORE;
	}
};