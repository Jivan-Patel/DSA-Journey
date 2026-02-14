/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function (n) {
    let temp = n.toString();
    let m1 = -1;
    let m2 = -1;
    for (let i = 0; i < temp.length; i++) {
        if (temp[i] >= m1) {
            m2 = m1;
            m1 = temp[i];
        }
        else if (temp[i] > m2) {
            m2 = temp[i];
        }
    }
    return m1 * m2;
};
