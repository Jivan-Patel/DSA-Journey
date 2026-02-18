/**
 * @param {number[]} arr
 * @return {boolean}
 */
var checkIfExist = function (arr) {
    let seen = new Set();
    for (let i = 0; i < arr.length; i++) {
        if (seen.has(arr[i] * 2)) return true;
        if (arr[i]%2===0 && seen.has(arr[i] / 2)) return true;
        seen.add(arr[i]);
    }
    return false;
};
