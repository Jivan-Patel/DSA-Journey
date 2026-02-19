/**
 * @param {number[]} order
 * @param {number[]} friends
 * @return {number[]}
 */
var recoverOrder = function(order, friends) {
    let set = new Set(friends);
    let res = [];
    for(let n of order) {
        if(set.has(n)) res.push(n);
    }
    return res;
};
