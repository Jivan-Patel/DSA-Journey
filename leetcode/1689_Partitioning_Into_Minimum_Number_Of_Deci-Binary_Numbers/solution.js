/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    const res = n.split('').reduce((max, digit) =>{
        if(max < digit) max = digit;
        return max;
    } ,(n[0]));
    return Number(res);
};