
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public int maxProduct(String[] words) {
        Map<Integer, Integer> bitmaskToWordLength = new HashMap<>();
        findBitmaskToWordLength(words, bitmaskToWordLength);
        return findMaxProduct(bitmaskToWordLength);
    }

    private int findMaxProduct(Map<Integer, Integer> bitmaskToWordLength) {
        int maxProduct = 0;
        for (int first : bitmaskToWordLength.keySet()) {
            for (int second : bitmaskToWordLength.keySet()) {
                if ((first & second) == 0) {
                    maxProduct = Math.max(maxProduct, bitmaskToWordLength.get(first) * bitmaskToWordLength.get(second));
                }
            }
        }
        return maxProduct;
    }

    private void findBitmaskToWordLength(String[] words, Map<Integer, Integer> bitmaskToWordLength) {
        for (String word : words) {
            int bitmask = 0;
            for (int i = 0; i < word.length(); ++i) {
                bitmask |= 1 << bitPosition(word.charAt(i));
            }
            int newLength = Math.max(bitmaskToWordLength.getOrDefault(bitmask, 0), word.length());
            bitmaskToWordLength.put(bitmask, newLength);
        }
    }

    private int bitPosition(char letter) {
        return letter - 'a';
    }
}
