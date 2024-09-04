/*
 * Programmers FE DevCourse 8th week ... (1)
 * Author: 김주영
 * Date: 24. 9. 4
 * Prob Number: 138477
 * Prob Description: k개 자리가 지정되있는 명예의 전당에 매일 점수가 하나씩 추가된다고 할때 모든 날의 k등을 구하라.
 */

function solution(k, score) {
  var answer = [];
  let hallOfFame = [];

  score.map((v) => {
    hallOfFame.push(v);

    let min = Math.min(...hallOfFame);

    if (hallOfFame.length > k) {
      // 명예의 전당이 다 찬 경우
      hallOfFame.splice(hallOfFame.indexOf(min), 1);
      answer.push(Math.min(...hallOfFame));
    } else {
      answer.push(min);
    }
  });
  return answer;
}
// hallOfFame에 원소를 하나씩 push
// 크기 측정 후 안넘치면 최솟값을 answer에 넣기
// 넘치면 최솟값 제거 후 다시 최솟값 구해서 answer에 넣기

function solution(k, score) {
  var answer = [];
  var arr = [];

  score.map((v, i) => {
    arr.push(v);
    arr.sort((a, b) => b - a);

    if (i < k) answer.push(...arr.slice(-1));
    else answer.push(arr[k - 1]);
  });

  return answer;
}
// 원소를 하나씩 집어넣고 sort를 한다.
// k번째 자리에 있는 놈들만 answer에 push한다.
// ** .slice(시작, 끝) 과 .splice(시작, 제거개수) 헷갈리지 말자. **

function solution(k, score) {
  const stack = [];
  return score.reduce((a, c) => {
    if (stack.length < k) {
      stack.push(c);
      stack.sort((a, b) => a - b);
    } else {
      stack.push(c);
      stack.sort((a, b) => a - b);
      stack.shift();
    }
    a.push(stack[0]);
    return a;
  }, []);
}
// 다른 사람 풀이
// 오름차순으로 sort한 후 첫 원소 제거하는 방식.
// reduce를 사용하여 정답을 accumulate 하도록 만든 것이 인상적이었음.
