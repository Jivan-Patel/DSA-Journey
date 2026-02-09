/**
 * @param {string[]} operations
 * @return {number}
 */
var calPoints = function(operations) {
    let res = [];
    let req = 0;
    for(let i = 0; i < operations.length; i++) {
        switch(operations[i]) {
            case '+':
                let sum = res[res.length - 1] + res[res.length - 2]
                res.push(sum);
                req += sum;
                break;
            case 'C':
                req -= res.pop();
                break;
            case 'D':
                let dbl = res[res.length - 1] * 2;
                res.push(dbl);
                req += dbl;
                break;
            default:
                let num= Number(operations[i])
                res.push(num);
                req += num;
                break;
        }
    }
    return req;
};
