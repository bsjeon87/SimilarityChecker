
#include <string>
#include <set>

using std::string;
using std::set;

class SimilarityChecker {
private:
	int MAX_LENGTH_SCORE = 60;
public:
	float getLengthScore(const string& inputA, const string& inputB) {
		const int inputALen = inputA.length();
		const int inputBLen = inputB.length();
		const int longInputLength = (inputALen > inputBLen) ? inputALen : inputBLen;
		const int shortInputLength = (inputALen < inputBLen) ? inputALen : inputBLen;
		const int gap = longInputLength - shortInputLength;

		return (1 - ((float)gap / shortInputLength)) * MAX_LENGTH_SCORE;
	}

	float getAlphaScore(const string& inputA, const string& inputB) {
		set<char> charForA;
		set<char> charForB;
		int sameCnt = 0;
		int totalCnt = 0;

		for (char input : inputA) {
			charForA.insert(input);
		}
		for (char input : inputB) {
			charForB.insert(input);
		}

		for (char input : charForA) {
			if (charForB.find(input) != charForB.end()) {
				sameCnt++;
			}
		}
		totalCnt = (charForA.size() + charForB.size() - sameCnt);

		return ((float)sameCnt / totalCnt) * 40;
	}

	float getScore(const string& inputA, const string& inputB) {
		return getLengthScore(inputA, inputB) + getAlphaScore(inputA, inputB);
	}
};