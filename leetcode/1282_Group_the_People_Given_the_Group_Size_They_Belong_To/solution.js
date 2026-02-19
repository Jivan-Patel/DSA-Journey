/**
 * @param {number[]} groupSizes
 * @return {number[][]}
 */
var groupThePeople = function (groupSizes) {
    let obj = {};
    for (let i = 0; i < groupSizes.length; i++) {
        if (obj[groupSizes[i]]) obj[groupSizes[i]].push(i)
        else obj[groupSizes[i]] = [i];
    }
    let res = [];
    for(let key in obj) {
        if(Number(key) >= obj[key].length) res.push(obj[key]);
        else {
            let i = 0;
            let temp = [[]];
            for(let size of obj[key]) {
                if(Number(key) <= temp[i].length) {
                    temp.push([])
                    i++;
                }
                temp[i].push(size);
            }
            res.push(...temp)
        }
    }
    return res;
};