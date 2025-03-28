
#include <string>

using std::string;

class SimilarityChecker {
public:
	int getLengthScore(string inputA, string inputB)
	{
		const static int MAX_LENGTH_SCORE = 60;
		const int inputALen = inputA.length();
		const int inputBLen = inputB.length();
		const int longInputLength = (inputALen > inputBLen) ? inputALen : inputBLen;
		const int shortInputLength = (inputALen < inputBLen) ? inputALen : inputBLen;
		const int gap = longInputLength - shortInputLength;

		return (1 - gap / shortInputLength) * MAX_LENGTH_SCORE;
	}
};