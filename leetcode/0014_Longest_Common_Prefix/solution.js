/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    let len = null;
    let maxS = strs[0]
    if (maxS == "") return ""
    for (let i = 1; i < strs.length; i++) {
        let c = 0;
        let s = ""
        while ((maxS.length > c)) {
            if (maxS[c] === strs[i][c]) {
                s += strs[i][c]
                c++;
            }
            else break
        }
        maxS = s
    }
    return maxS;
};