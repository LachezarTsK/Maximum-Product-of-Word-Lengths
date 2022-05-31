
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;

class Solution {
    
    inline static const int ALPHABET_SIZE = 26;
    typedef unordered_map<bitset<ALPHABET_SIZE>, int> mapBitmaskToLength;

public:
    int maxProduct(vector<string>& words) {
        mapBitmaskToLength bitmaskToWordLength;
        findBitmaskToWordLength(words, bitmaskToWordLength);
        return findMaxProduct(bitmaskToWordLength);
    }
    
private:
    int findMaxProduct(const mapBitmaskToLength& bitmaskToWordLength) {
        int maxProduct = 0;
        for (const auto bitsFirst : bitmaskToWordLength) {
            for (const auto bitsSecond : bitmaskToWordLength) {
                if ((bitsFirst.first & bitsSecond.first) == 0) {
                    maxProduct = max(maxProduct, bitsFirst.second * bitsSecond.second);
                }
            }
        }
        return maxProduct;
    }

    void findBitmaskToWordLength(const vector<string>& words, mapBitmaskToLength& bitmaskToWordLength) {
        for (const auto& word : words) {
            bitset<26> bitmask;
            for (int i = 0; i < word.length(); ++i) {
                bitmask.set(bitPosition(word[i]));
            }
            int newLength = max(bitmaskToWordLength[bitmask], static_cast<int> (word.length()));
            bitmaskToWordLength[bitmask] = newLength;
        }
    }

    int bitPosition(char letter) {
        return letter - 'a';
    }
};
