/**
 * @param {Function} fn
 * @return {Function}
 */

// 전달인자 == 함수(더하기, 피보나치, ...)
// 반환인자 == 변환된 함수(같은 input에 대해서는 계산하지 않는 같은 역할의 함수)

// https://www.youtube.com/watch?v=oFXyzJt9VeU [영상참고함]
// Decorator Design pattern.

function memoize(fn) {
    const cache = {};

    return function(...args) {
        const key = JSON.stringify(args);
        console.log('stringify:'+key);

        if(key in cache) return cache[key];

        cache[key] = fn(...args);
        return cache[key];
    }
}
 
 let callCount = 0;
 const memoizedFn = memoize(function (a, b) {
  callCount += 1;
   return a + b;
 })
 memoizedFn(2, 3) // 5
 memoizedFn(2, 3) // 5
 console.log(callCount) // 1 
 