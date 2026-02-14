/**
 * @param {string[][]} items
 * @param {string} ruleKey
 * @param {string} ruleValue
 * @return {number}
 */
var countMatches = function (items, ruleKey, ruleValue) {
    let cqIndex = null;
    switch (ruleKey) {
        case "type":
            cqIndex = 0;
            break;

        case "color":
            cqIndex = 1;
            break;

        case "name":
            cqIndex = 2;
            break;
    }
    return items.reduce((count,item) =>{
        if(item[cqIndex] === ruleValue) return count + 1;
        else return count;
    },0);
};