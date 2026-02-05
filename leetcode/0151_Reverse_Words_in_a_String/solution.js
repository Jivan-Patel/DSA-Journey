/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let arr = s.split(" ");
    let resArr = [];

    for(let i = arr.length -1; i>=0; i--) {
        if(arr[i]) resArr.push(arr[i]);
    }

    return resArr.join(" ")

};