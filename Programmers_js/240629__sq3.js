// 괄호 (와 )로 이루어진 string의 괄호가 다 잘 짝지어지는지 확인하는 문제.
// 구현해본거라 + 쉬운 버전이라 풀이가 매우 쉬웠음

// 주영
// 생각해보니 그냥 왼쪽 괄호 숫자만 세어줘도 됐네
function solution(s) {
    var stack = [];
    var len = s.length;
    
    for(let i=0; i<len; i++) {
        if(s[i]==='(')
            stack.push('(');
        else if(stack.length == 0)
            return false;
        else
            stack.pop();
    }
    if(stack.length != 0) return false;
    else return true;
}

// 외
// 훨씬 간단하게 구현이 되는구나.. 사실 괄호 종류가 하나니까 열린괄호 숫자만 잘 체크해주면 문제가 풀리네.
function solution(s){
    let cum = 0
    for (let paren of s) {
        cum += paren === '('? 1: -1
        if(cum < 0) {
            return false
        }
    }
    return cum === 0? true: false;
}

// 1. Array의 match 함수: /.../ 사이에 정규표현식을 사용하여 이용한다. 이 코드에서 "/(\(|\))/g"는 왼괄호나 오른괄호를 모두 찾아서 array로 반환하는 것이다.
// 알고리즘이 신기한데 처음 괄호가 열린괄호고 총 괄호 갯수가 짝수라면 true, 아니면 false를 반환한다. 하지만 보니까 ())( 이런 경우에도 통과 되므로 문제를 통과하진 못한다. 이전에 어떻게 통과했지?
function is_pair(s){
    var result = s.match(/(\(|\))/g);
    return result[0] == '(' && result.length % 2 == 0 ? true : false
  }

