// 문자열의 왼쪽부터 차례대로 하나씩 확인할 때, 처음 확인한 알파벳과 일치하는 알파벳의 수와 일치하지 않는 알파벳의 수가 같아질 때마다 문자열을 자를때 최종적으로 몇개의 문자열로 잘릴지 계산하는 문제.

// 주영
function solution(s) {
  var answer = 1;
  var count1 = 0,
    count2 = 0;
  var len = s.length;
  var char = s[0];

  for (let i = 0; i < len; i++) {
    if (s[i] === char) count1++;
    else count2++;

    if (count1 === count2) {
      if (i == len - 1) break;
      answer++;
      count1 = 0;
      count2 = 0;
      char = s[i + 1];
    }
  }

  return answer;
}

// 외
// 조금 더 고민했다면 이렇게 간단히 만들 수 있었을 듯!!
function solution(s) {
  let answer = 0;
  let current;
  let count = 0;

  for (let i = 0; i < s.length; i++) {
    if (count === 0) {
      answer++;
      current = s[i];
      count = 1;
    } else {
      if (current !== s[i]) count--;
      else count++;
    }
  }

  return answer;
}

// 재귀로 푸는 신박한 방법! 하지만 성능은 낮다고 함.
// " 문자열을 s[0], s[i] 로 바로 접근할 수 있음에도 불구하고 새로운 열로 split, join 하는 과정에서 성능, 메모리 면에서 나빠지는 것 같습니다"
// => split, join등은 시간을 많이 잡아먹는다!
function solution(s, count = 0) {
  // s가 빈배열일 경우에도 처리를 했다!
  if (!s) return count;

  // 첫 문자인 first와 나머지인 rest 구분하기! 이렇게 가능할 줄은 몰랐다.☆☆☆
  let [first, ...rest] = s.split("");
  let countSame = 1;
  let countInSame = 0;

  let i = 0;
  for (; i < rest.length; i++) {
    if (rest[i] === first) countSame++;
    else countInSame++;
    if (countSame === countInSame) break;
  }

  // rest를 i+1인덱스부터 끝까지 잘라서 string으로 만들어서 파라미터 전해주기.
  return solution(rest.slice(i + 1).join(""), count + 1);
}
