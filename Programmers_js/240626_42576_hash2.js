// 참가자 이름 명단과 완료자 이름 명단 사이 완료하지 않은 한 사람의 이름 찾기 (중복 이름 존재 가능)

// 주영
function solution(participant, completion) {
    var p_len = participant.length;
    var c_len = completion.length;
    var map = new Map();

    for(let i=0; i<p_len; i++) {
        if(map.has(participant[i]))
            map.set(participant[i], map.get(participant[i]) + 1);
        else
            map.set(participant[i], 0);    
    }

    for(let i=0; i<c_len; i++) {
        if(map.get(completion[i]) != 0)
            map.set(completion[i], map.get(completion[i]) -1);
        else
            map.delete(completion[i]);
    }

    return [...map.keys()][0];
}

// 외
// https://school.programmers.co.kr/learn/courses/30/lessons/42576/solution_groups?language=javascript
// 모르는 거 너무 많아서 일단 보류...;;
// 댓글도 도움 되는거 많음!

var solution1=(_,$)=>_.find(_=>!$[_]--,$.map(_=>$[_]=($[_]|0)+1))

var solution1=(participant,completion)=>participant.find(name=>!completion[name]--, completion.map(name=>completion[name]=(completion[name]|0)+1))
// find 두번째 arg값을 첫번째 arg값에서 찾아라.

var solution1 = (participant,completion) => { 
    completion.map(name => completion[name] = (completion[name]|0)+1);
    return participant.find((name) => !completion[name]--); 
};

function solution2(participant, completion) {
    const map = new Map();

    for(let i = 0; i < participant.length; i++) {
        let a = participant[i], 
            b = completion[i];

        map.set(a, (map.get(a) || 0) + 1);
        map.set(b, (map.get(b) || 0) - 1);
    }

    for(let [k, v] of map) {
        if(v > 0) return k;
    }

    return 'nothing';
}