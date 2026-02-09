/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumCount = function(nums) {
    let pcount = 0;
    let ncount = 0;
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] > 0) pcount++;
        else if(nums[i] < 0) ncount++;
    }
    return (pcount>ncount) ? pcount : ncount;
};