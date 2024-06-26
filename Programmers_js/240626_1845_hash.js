// 여러 N개의 포켓몬 중 N/2개를 고르는데 최대한 다양한 개수의 포켓몬 고르기

// 주영
function solution(nums) {
    var N = nums.length;
    var pkm = new Map();

    for(let i=0; i<N; i++) {
        if(pkm.get(nums[i]) == undefined) {
            pkm.set(nums[i], 0);
        }     
    }

    if(pkm.size < N/2) return pkm.size;
    else return N/2;
}
console.log(solution2([1,2,3]))

// 외
// 1. Set에 바로 array를 넣어줄 수 있구나!
// 2. js도 삼항 연산자 있구나!
// 3? 왜 arr에 ...을 넣은거지?
//      => spread 연산자: Set 객체를 배열로 변환하는 방법입니다. ... (spread 연산자)는 Set의 각 요소를 개별적으로 추출하여 새로운 배열에 담아줍니다.
//      => arr로 바꿔서 .length 해주는게 set.size보다 빨라서 arr로 바꿔준듯 함. (추측)

function solution1(nums) {
    const max = nums.length / 2;
    const arr = [...new Set(nums)];
  
    return arr.length > max ? max : arr.length
}

function solution2(nums) {
    return Math.min(nums.length/2,[...new Set(nums)].length);
}