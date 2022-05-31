
/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function (words) {
    this.ascii_a = 97;
    const bitmaskToWordLength = new Map();
    findBitmaskToWordLength(words, bitmaskToWordLength);
    return findMaxProduct(bitmaskToWordLength);
};

/**
 * @param {Map key: number, value: number} bitmaskToWordLength
 * @return {number}
 */
function findMaxProduct(bitmaskToWordLength) {
    let maxProduct = 0;
    for (let first of bitmaskToWordLength.keys()) {
        for (let second of bitmaskToWordLength.keys()) {
            if ((first & second) === 0) {
                maxProduct = Math.max(maxProduct, bitmaskToWordLength.get(first) * bitmaskToWordLength.get(second));
            }
        }
    }
    return maxProduct;
}

/**
 * @param {string[]} words
 * @param {Map key: number, value: number} bitmaskToWordLength
 * @return {void}
 */
function findBitmaskToWordLength(words, bitmaskToWordLength) {
    for (let word of words) {
        let bitmask = 0;
        for (let i = 0; i < word.length; ++i) {
            bitmask |= 1 << bitPosition(word.charAt(i));
        }
        if (!bitmaskToWordLength.has(bitmask)) {
            bitmaskToWordLength.set(bitmask, word.length);
            continue;
        }
        let newLength = Math.max(bitmaskToWordLength.get(bitmask), word.length);
        bitmaskToWordLength.set(bitmask, newLength);
    }
}

/**
 * @param {character} letter
 * @return {number}
 */
function bitPosition(letter) {
    return letter.codePointAt(0) - this.ascii_a;
}
