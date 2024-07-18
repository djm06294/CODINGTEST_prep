// 알파벳에서 string인 skip에 있는 모든 알파벳을 제외한 후에 string s의 모든 알파벳을 index만큼 뒤에 있는 알파벳으로 바꾸고 반환하기.

// 주영
//
function solution(s, skip, index) {
  var answer = "";
  var alphabets = "abcdefghijklmnopqrstuvwxyz";
  var s_len = s.length,
    skip_len = skip.length;

  // 알파벳에서 skip 제외하기
  for (let i = 0; i < skip_len; i++) {
    let tmp = alphabets.indexOf(skip[i]);
    alphabets = alphabets.substr(0, tmp) + alphabets.substr(tmp + 1);
  }

  // s 변형시켜서 answer에 저장하기
  let alpa_len = alphabets.length;
  for (let i = 0; i < s_len; i++) {
    let tmp = alphabets.indexOf(s[i]) + index;
    answer += alphabets[tmp % alpa_len];
  }
  return answer;
}

// 외
// 1. Array.includes() : 괄호 안의 값 유무에 따라 true/false 반환
// 2. Array.join() : 지정된 문자를 끼워 배열을 연결하여 문자열 반환
// 함수를 몰라서 못썼다기 보다 더 고민해보지 못했던 것 같다..
function solution(s, skip, index) {
  const alphabet = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
  .filter((c) => !skip.includes(c));

  return s
    .split("")
    .map((c) => alphabet[(alphabet.indexOf(c) + index) % alphabet.length])
    .join("");
}

// 1. String.match(reqexp) : 정규식(reqexp)와 매치되는 부분을 검색한다. -> 아직 정규식은 배워보지 못했다. ☆
// 코드가 깔끔하다..@
const solution = (s, skip, index) => {
  let ans = "";
  const matched = "abcdefghijklmnopqrstuvwxyz".match(
    new RegExp(`[^${skip}]`, "g")
  );
  for (const c of s) {
    const newIdx = matched.indexOf(c) + index;
    ans += matched[newIdx % matched.length];
  }
  return ans;
};
