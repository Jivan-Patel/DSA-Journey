/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function (address) {
    let res = [];
    for (let i = 0; i < address.length; i++) {
        if (address[i] === ".") res.push('[', '.', ']');
        else res.push(address[i]);
    }
    return res.join('');
};