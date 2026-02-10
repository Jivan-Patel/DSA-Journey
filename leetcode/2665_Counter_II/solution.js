/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
    let initial_Value = init;
    let current = init;
    return {
        increment: () => ++current,
        decrement: () => --current,
        reset: () => current = initial_Value,
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */