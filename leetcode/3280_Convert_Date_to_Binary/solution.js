/**
 * @param {string} date
 * @return {string}
 */
var convertDateToBinary = function (date) {
    function toBinary(num) {
        num = Number(num)
        let res = "";
        while (num != 0) {            
            res = (num % 2) + res;
            num = Math.floor(num / 2);
        }
        return res;
    }
    return date.split('-').map((num) => toBinary(num)).join('-')
};