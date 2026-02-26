/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {number}
 */
var findClosest = function (x, y, z) {
    let d1 = Math.abs(x-z);
    let d2 = Math.abs(y-z);
    return (d1 < d2) ? 1 : (d2 < d1) ? 2 : 0;
};
