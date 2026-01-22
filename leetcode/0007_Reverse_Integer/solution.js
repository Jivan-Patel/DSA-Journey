/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let temp = null;
    if(x>=0) {
        temp = x;
        sign = 1;
    }
    else{
        temp =-x;
        sign = -1;
    }

    let res = 0;
    while(temp != 0){
        res = (res*10) + (temp%10);
        temp = Math.floor(temp / 10);
    }

    return (res*sign>= -(2**31) && res*sign <= ((2**31) - 1)) ? res*sign : 0;
};