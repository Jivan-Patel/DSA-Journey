/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    let obj = {};
    let res = -1;
    for(let num of arr) {
        if(obj[num]) obj[num]++;
        else obj[num] = 1;
    }
    for(let key in obj) {
        if(obj[key] == Number(key)) res = (res < Number(key)) ? Number(key) : res;
    }
    return res;
};