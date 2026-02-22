/**
 * @param {string[][]} responses
 * @return {string}
 */
var findCommonResponse = function(responses) {
    let res = [];
    let freq = {};
    for(let response of responses) {
        let set = new Set(response);
        res.push(set);
    }
    for(let set of res) {
        for(let resp of set) {
            if(freq[resp]) freq[resp]++;
            else freq[resp] = 1;
        }
    }
    let max = [null, -Infinity];
    for(let response in freq) {
        if(freq[response] > max[1] || (freq[response] === max[1] && response < max[0])){
            max = [response,freq[response]]
        } 
    }
    return max[0];
};