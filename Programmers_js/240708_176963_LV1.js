// 이름 배열과 그에 따른 그리움 점수가 담긴 배열이 주어졌을 때, 각 사진의 그리움 점수 계산해보기

// 주영
// 1. 생각해보자 잘못된 것이 무엇인지?
function solution(name, yearning, photo) {
    var answer = [];
    var map = [];
    var p_num = photo.length;
    name.forEach((n, i) => {
        map[n] = yearning[i];
    });

    for(let i=0; i<p_num; i++) {
        let tmp = 0;
        let p = photo[i];
        let l = p.length;
        
        // 다른 코드 보니 이렇게 이중문으로 할 필요 없이 아래와 같이 구현해도 됨!
        // p.forEach(v => {tmp += map[v] ? map[v] : 0});
        // p.forEach(v => {tmp += map[v] ?? 0})
        for(let j=0; j<l; j++) {
            if(map[p[j]] != undefined)
                tmp += map[p[j]];
        }
        answer.push(tmp);
    }

    return answer;
}


// 외
// 1. "??" null 병합 연산자 : 왼쪽 피연산자가 null or undefined가 아니면 반환, 맞으면 오른쪽 피연산자 반환하는 논리 연산자.
// 2. indexOf() : 어떤 값이 그 배열의 몇번째 idx에 있는지 바로 반환이 가능한가보다.
function solution(name, yearning, photo) {
    return photo.map((v)=> 
        v.reduce((a, c) => a += yearning[name.indexOf(c)] ?? 0, 0)
    );
}

// key-val로 해쉬를 해준 것은 나와 같다! 그리고는 위 코드 처럼 축약하여 구현하셨다.
function solution(name, yearning, photo) {
    let obj = {};
    for(let i = 0; i < name.length; i++){
        obj[name[i]] = yearning[i];
    }
    return photo.map(value => value.map(v => obj[v] ? obj[v] : 0).reduce((acc,cur) => acc + cur,0))
}