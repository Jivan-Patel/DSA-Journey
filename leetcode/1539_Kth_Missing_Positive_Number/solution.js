/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function (arr, k) {
    let flag = 0;
    let check = 1;
    let i = 0;
    while (check <= arr[arr.length - 1]) {
        if (arr[i] != check) {
            flag++;
            if (flag === k) return check;
        }
        else i++;
        check++;
    }
    return arr.pop() + k - flag;
};