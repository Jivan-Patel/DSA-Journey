/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function (grid) {
    let count = 0;
    for (let arr of grid) {
        let i = arr.length - 1;
        while (arr[i] < 0 && i >= 0) {
            count++;
            i--;
        }
    }
    return count;
};