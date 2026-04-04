var removeDuplicates = function (nums) {
    let i = 0;
    while (i < nums.length) {
        let j = 1;
        while (nums[i] === nums[i + j] && j < nums.length) {
            j++;
        }
        nums.splice(i, j - 1);
        i++;
    }
    return nums.length;
};