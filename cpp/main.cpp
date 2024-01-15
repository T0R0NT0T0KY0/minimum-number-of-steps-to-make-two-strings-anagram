#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, unsigned short> sCharCountMap;
        unordered_map<char, unsigned short> tCharCountMap;

        for (int i = 0; i < s.size(); ++i) {
            sCharCountMap[s.at(i)]++;
            tCharCountMap[t.at(i)]++;
        }

        int steps = 0;

        for (auto const &[sChar, sCharCount]: sCharCountMap) {
            auto tCharCountIterator = tCharCountMap.find(sChar);
            unsigned short tCharCount = tCharCountIterator != tCharCountMap.end() ? tCharCountIterator->second : 0;

            steps += max(sCharCount - tCharCount, 0);
        }

        return steps;
    }
};

int main() {
    Solution solution;
    int res1 = solution.minSteps("bab", "aba");
    cout << "test1: " << res1 << endl;

    int res2 = solution.minSteps("leetcode", "practice");
    cout << "test2: " << res2 << endl;

    int res3 = solution.minSteps("anagram", "mangaar");
    cout << "test3: " << res3 << endl;

    return 0;
}
