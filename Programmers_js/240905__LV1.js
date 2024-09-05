/*
 * Programmers FE DevCourse 8th week ... (3)
 * Author: 김주영
 * Date: 24. 9. 5
 * Prob Number: 135808
 * Prob Description: 과일 장수
 */

function solution(k, m, score) {
  var answer = 0;

  const leftover = score.length % m;
  score.sort((a, b) => a - b);

  // leftover 개수만큼 낮은품질의 사과 제거
  for (let i = 0; i < leftover; i++) score.shift();

  score.map((v, i) => {
    if (i % m === 0) answer += v * m;
  });
  return answer;
}
// 총 사과 개수 % m개 => 상자를 만들고 남는 사과 수 계산
// 남는 사과 수만큼 최솟값을 제외
// 남은 사과를 낮은 품질 부터 m개씩 박스에 담기.

function solution(k, m, score) {
  let answer = 0;
  const sortedScore = score
    .slice()
    .sort((a, b) => a - b)
    .slice(score.length % m);
  for (let i = 0; i < sortedScore.length; i += m) {
    answer += sortedScore[i] * m;
  }
  return answer;
}
// 다른 사람 풀이
// .slice()로 copy를 했다.
// .slice(idx)는 idx부터 끝까지 원소를 반환한다.

solution = (_, m, s) =>
  s
    .sort()
    .filter((_, i) => !((s.length - i) % m))
    .reduce((a, v) => a + v, 0) * m;
// 다른 사람 풀이
// 오름차순 정렬 후, 배열 끝에서부터 m번째 요소만 선택, 총 합산한 후 m을 곱해 반환한다.
