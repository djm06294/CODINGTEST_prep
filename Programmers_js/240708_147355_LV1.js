// t와 p 두개의 숫자로 된 문자열이 있을 때 p와 길이가 같은데 더 작은 숫자를 t에서 뽑아낼 수 있는 부분 문자열의 개수 구하기..!(?)

// 알고리즘 kit 풀다가 조금 벽 느껴서 더 많은 문제를 풀어보려고 LV.1 문제 중 정답률 70% 넘는거 풀어보려고 했는데 5-60%로 낮춰도 괜춘할듯~~~

function solution(t, p) {
    var answer = 0;
    var t_len = t.length;
    var p_len = p.length;

    for(let i=0; i<=t_len-p_len; i++) {
        let s = t.substr(i, p_len);
        if(Number(s) <= Number(p)) answer++;        
    }
    return answer;
}

// 외
// 1. 문자열을 숫자로 바꾸고 싶다면 앞에 +만 붙여주면 된다!
//        if(+s <= +p) answer++;  