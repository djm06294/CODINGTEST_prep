// string s의 각 알파벳이 자신보다 앞에 자신과 같은 알파벳이 있는지 확인한 후 떨어진 거리를 담은 배열을 반환하라.

// 주영
function solution(s) {
  var answer = [];
  var alpha_idx = [];
  var len = s.length;

  for (let i = 0; i < len; i++) {
    let tmp = alpha_idx[s[i]];
    if (tmp === undefined) {
      answer.push(-1);
      alpha_idx[s[i]] = i;
    } else {
      answer.push(i - tmp);
      alpha_idx[s[i]] = i;
    }
  }
  return answer;
}

// 외
// 1. 스프레드 연산자(...) : 이 연산자는 배열, 문자열, 객체 등 반복 가능한 객체의 모든 요소를 개별 요소로 확장하는 데 사용됩니다. (gpt)
// => 그러니까 string 같은 것을 하나하나 풀어서 배열로 만들어준다고 보면 됨.
// 항상 map을 사용하면 훨씬 깔끔해지는 것 같다..!
function solution(s) {
  const hash = {};

  return [...s].map((v, i) => {
    let result = hash[v] !== undefined ? i - hash[v] : -1;
    hash[v] = i;
    return result;
  });
}

// 1. Array.slice(idx1, idx2) : idx1부터 idx2까지의 원소를 얕은 복사해서 반환.
const solution = (s) =>
  [...s].map((char, i) => {
    const count = s.slice(0, i).lastIndexOf(char);
    return count < 0 ? count : i - count;
  });

// 자체 난독화 코드. 한번 읽어보자...
function solution(s) {
  const t = [...new Set(s.split(""))];
  const q = s.split("");
  let c = [];
  const b = [];
  const tlqkf = [];
  for (let j = 0; j < t.length; j++) {
    for (let i = 0; i < q.length; i++) {
      if (q[i] === t[j]) {
        c.push(i);
      }
    }
    b.push(c);
    c = [];
  }
  const cccc = Array.from({ length: s.length }, (_, x) => 0);
  const qqqq = b.map((v) =>
    v.map((vv, i, a) => (i === 0 ? -1 : a[i] - a[i - 1]))
  );
  for (let i = 0; i < s.length; i++) {
    for (let j = 0; j < qqqq.length; j++) {
      if (qqqq[j][i] !== undefined) {
        cccc[b[j][i]] = qqqq[j][i];
      }
    }
  }
  return cccc;
}
