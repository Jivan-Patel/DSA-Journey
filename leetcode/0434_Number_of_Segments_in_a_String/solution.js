/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    let res = s.split(' ').filter((word => word != '')).length
    return res;
};