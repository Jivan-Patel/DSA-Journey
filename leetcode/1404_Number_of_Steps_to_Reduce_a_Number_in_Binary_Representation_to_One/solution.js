/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function (s) {
    let operation = 0;
    s = s.split('');
    while (s.length > 1) {
        operation++;
        if (s[s.length - 1] === '0') {
            s.pop();
        }
        else {
            let j = s.length - 1;
            while (s[j] != '0') {
                s[j] = '0';
                if(j <= 0) {
                    s.unshift('1');
                    break;
                }
                j--;
            }
            s[j] = '1';
        }
    }
    return operation;
};