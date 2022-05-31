
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> bitmaskToWordLength;
        findBitmaskToWordLength(words, bitmaskToWordLength);
        return findMaxProduct(bitmaskToWordLength);
    }
    
private:
    int findMaxProduct(unordered_map<int, int>& bitmaskToWordLength) {
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

    void findBitmaskToWordLength(const vector<string>& words, unordered_map<int, int>& bitmaskToWordLength) {
        for (const auto& word : words) {
            int bitmask = 0;
            for (int i = 0; i < word.length(); ++i) {
                bitmask |= 1 << bitPosition(word[i]);
            }
            int newLength = max(bitmaskToWordLength[bitmask], static_cast<int> (word.length()));
            bitmaskToWordLength[bitmask] = newLength;
        }
    }

    int bitPosition(char letter) {
        return letter - 'a';
    }
};
