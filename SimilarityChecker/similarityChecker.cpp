
#include <string>

using std::string;

class SimilarityChecker {
private:
	int MAX_LENGTH_SCORE = 60;

	float getLengthScore(const string& inputA, const string& inputB) {
		const int inputALen = inputA.length();
		const int inputBLen = inputB.length();
		const int longInputLength = (inputALen > inputBLen) ? inputALen : inputBLen;
		const int shortInputLength = (inputALen < inputBLen) ? inputALen : inputBLen;
		const int gap = longInputLength - shortInputLength;

		return (1 - ((float)gap / shortInputLength)) * MAX_LENGTH_SCORE;
	}
public:
	float getScore(const string& inputA, const string& inputB) {
		return getLengthScore(inputA, inputB);
	}
};