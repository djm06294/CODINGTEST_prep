/**
 * @return {Function}
 */


var createHelloWorld = function() {
    
    return function(...args) {
        
    }
};

// ===========================================

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let _n = n;
    return function() {
        return _n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

// ===========================================

/**
 * @param {string} val
 * @return {Object}
 */

var expect = function(val) {
    var object = {
        'toBe' : function(expected) {
            if(val===expected) return true
            else throw new Error("Not Equal")
        },
        'notToBe' : function(expected) {
            if(val!==expected) return true
            else throw new Error("Equal")
        }
    }
    return object
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */

// ===========================================

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    return {
        'counter': init,
        'increment': function() {
            return ++this.counter
        },
        'decrement': function() {
            return --this.counter
        },
        'reset': function() {
            this.counter = init
            return this.counter
        }
    }
};

// 뒤에거가 더 좋은 코드인듯
var createCounter = function(init) {
    let counter = init
    return {
        increment:()=> {
            return ++counter
        },
        'decrement': ()=> {
            return --counter
        },
        'reset': ()=> {
            counter = init
            return counter
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

// ===========================================

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let arrT = []
    for(let i = 0; i < arr.length; i++)
        arrT.push(fn(arr[i], i))
        
    return arrT    
};

// ===========================================

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let arrT = []
    for(let i=0; i<arr.length; i++) {
        if(fn(arr[i], i) != false)      // ""== true"로 하면 1만 통과시킴.
            arrT.push(arr[i])
    }
    return arrT    
};

// ===========================================

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let val = init
    for(let i=0; i<nums.length; i++) {
        val = fn(val, nums[i])
    }
    return val
};

var reduce = function(nums, fn, init) {
    let state = init;

    nums.forEach(function(item, index) {    // 이런 방식도 있네?
        state = fn(state, item)
    })

    return state;
};

// ===========================================

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        let val = x
        let len = functions.length
        for(let i=len-1; i>=0; i--) {
            val = functions[i](val)
        }
        return val
        
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */

// ===========================================

/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    var check=0
    return function(...args){
        if(check==1) return undefined
        check=1
        return fn(...args)
    }
};

var once = function(fn) {  //!!?
    let called = false;
        let result;
    
      return function(...args) {
        if (!called) {
          called = true;
          result = fn.call(this, ...args);
        } else {
          return undefined
        }
        return result;
      };
    };
    
    /**
     * let fn = (a,b,c) => (a + b + c)
     * let onceFn = once(fn)
     *
     * onceFn(1,2,3); // 6
     * onceFn(2,3,6); // returns undefined without calling fn
     */

// ===========================================
