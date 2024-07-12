// 문제: 페인트 칠하기..!

// 주영
function solution(n, m, section) {
    var answer = 1;
    var len = section.length;
    var st = section[0];
    for(let i=1; i<len; i++) {
        if(section[i] >= st+m) {
            answer++;
            st = section[i];
        }
    }
    return answer;
}

// 외
// 비슷한 알고리즘
function solution(n, m, sections) {
    var answer = 0;
    var painted = 0;
    for(var section of sections) {
        if(painted < section) {
            answer++;
            painted = section+m-1;
        }
    }
    return answer;
}

// 1. Array.from() : array like을 배열로 변경하는 메소드. 사실상 여기서는 필요 없음. 원래 배열이기 때문.
// 2. Array(n) : 배열 생성자. n 크기의 배열 생성. 요소는 모두 undefined.
// 3. fill(a, b, c) : b부터 c바로 전까지 a 값으로 바꾼다.
function solution(n, m, section) {
    let count = 0;
    const arr = Array.from(Array(n+1).fill(null));

    section.forEach(el =>{
        arr[el] = 1;
    })

    section.forEach(el=>{
        if(arr[el]){
            arr.fill(null, el, el+m)
            count++
        }
    })
    return count
}