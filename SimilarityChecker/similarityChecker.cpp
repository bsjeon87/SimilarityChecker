
#include <string>
#include <set>

using std::string;
using std::set;

class SimilarityChecker {
private:
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
public:
	float getScore(const string& inputA, const string& inputB) {
		return getAlphaScore(inputA, inputB);
	}
};