/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function (names, heights) {
    let len = names.length;
    let combArr = []
    let res = []
    for (let i = 0; i < len; i++) {
        combArr.push([names[i], heights[i]]);
    }
    combArr.sort((a, b) => b[1] - a[1]);
    for (let i = 0; i < combArr.length; i++) {
        res.push(combArr[i][0]);
    }
    return res;
};