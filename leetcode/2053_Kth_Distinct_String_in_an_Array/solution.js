/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function (arr, k) {
    let flag = 0;
    for (let i = 0; i < arr.length; i++) {
        let isUnique = true;
        for (let j = 0; j < arr.length; j++) {
            if (arr[i] === arr[j] && i != j) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            flag++;
            if (flag === k) return arr[i];
        }
    }
    return "";
};