/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function (arr) {
    let curDiff = Infinity;
    let curArr = [];
    arr = arr.sort((a, b) => a - b);
    for (let i = 0; i < arr.length; i++) {
        let abs = arr[i+1] - arr[i];
            if (abs < curDiff) {
                curDiff = abs;
                curArr = [[arr[i], arr[i+1]]]
            }
            else if (abs === curDiff) {
                curArr.push([arr[i], arr[i+1]])
            }
    }
    return curArr;
};