/*
 * Programmers FE DevCourse 8th week ... (2)
 * Author: 김주영
 * Date: 24. 9. 4
 * Prob Number: 136798
 * Prob Description: 1~number의 모든 정수가 갖는 약수 개수의 합을 구하기. (약수의 개수가 limit을 넘을 경우 power로 계산)
 */

function findDivisor(num) {
  let count = 0;
  for (let i = 1; i * i <= num; i++) {
    if (i * i === num) count++;
    else if (num % i === 0) count += 2;
  }
  return count;
}

function solution(number, limit, power) {
  var answer = 0;
  for (let i = 1; i <= number; i++) {
    let tmp = findDivisor(i);
    if (tmp > limit) tmp = power;
    answer += tmp;
  }

  return answer;
}
