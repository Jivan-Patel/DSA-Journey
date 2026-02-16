/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumPairRemoval = function (nums) {
    function checkAcc (arr) {
        for(let i = 0; i < arr.length - 1; i++) {
            if(arr[i] > arr[i + 1]) return false;
        }
        return true;
    }
    let check = checkAcc(nums);
    let count = 0;
    while(!check) {
        let minSum = Infinity;
        let j = 0;
        for(let i = 0; i < nums.length - 1; i++) {
            let sum = nums[i] + nums[i + 1];
            if(sum < minSum) {
                minSum = sum;
                j = i;
            }
        }
        nums.splice(j,2,minSum);
        check = checkAcc(nums);
        count++;
    }
    return count;
};