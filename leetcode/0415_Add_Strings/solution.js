/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function (num1, num2) {
    num1 = num1.toString();
    num2 = num2.toString();
    let i = num1.length - 1;
    let j = num2.length - 1;
    let result = "";
    let inc = 0;

    while (i >= 0 || j >= 0) {
        let sum = Number((num1[i] || 0)) + Number((num2[j] || 0)) + inc;
        if (sum >= 10) {
            sum -= 10;
            inc = 1;
        }
        else inc = 0;
        result = sum + result;
        i--;
        j--;
    }
    result = (inc || "") + result
    return result;
};
