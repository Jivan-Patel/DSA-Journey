/**
 * @param {string} command
 * @return {string}
 */
var interpret = function (command) {
    let res = [];
    for (let i = 0; i < command.length; i++) {
        if (command[i] === "(") {
            if (command[i + 1] == ')') {
                res.push('o');
                i++;
            }
            else{
                res.push("al");
                i += 3;
            }
        }
        else res.push(command[i])
    }
    return res.join('');
};