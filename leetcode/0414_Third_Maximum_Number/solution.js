/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function (nums) {

    let m1 = -Infinity;
    let m2 = -Infinity;
    let m3 = -Infinity;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > m1) {
            m3 = m2;
            m2 = m1;
            m1 = nums[i]
        }
        else if (nums[i] > m2 && nums[i] < m1) {
            m3 = m2;
            m2 = nums[i]
        }
        else if (nums[i] > m3 && nums[i] < m2) {
            m3 = nums[i]
        }
    }
    if(m3 != -Infinity ) return m3;
    if(m1 != -Infinity ) return m1;
    if(m2 != -Infinity ) return m2;
};
