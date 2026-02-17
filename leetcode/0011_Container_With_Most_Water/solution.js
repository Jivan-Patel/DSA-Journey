/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
    let max = 0;
    let i = 0;
    let j = height.length - 1;
    while (j > i) {
        let minI =(height[i] < height[j]) ? i : j;
        let area = height[minI] * (j - i);
        if (area > max) max = area;
        (minI === i) ? i++ : j--;
    }
    return max;
};