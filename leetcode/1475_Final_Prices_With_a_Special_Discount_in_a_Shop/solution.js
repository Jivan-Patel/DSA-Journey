/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function (prices) {
    for(let i = 0; i < prices.length - 1; i++) {
        let j = i + 1;
        while(prices[j] > prices[i] && j < prices.length) j++;
        if(j < prices.length) prices[i] = prices[i] - prices[j];
    }
    return prices;
};