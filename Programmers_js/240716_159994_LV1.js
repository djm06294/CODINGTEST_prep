// 두 단어 카드 더미에서 위에서부터 차례대로 카드를 뽑아 주어진 goal 문장을 만들 수 있는지 확인하는 문제.

// 주영
// 배열 순회할 때 of와 in의 역할이 조금 헷갈린다.
// 1. let i of arr : 일반적인 순회
// 2.arr.forEach( function(n) { } ) : 이 방법도 있네. 뭐가 다른가?
// +) i in arr : in은 순회에 쓰이는 것이 아니라 i라는 "index" 또는 "property"가 존재하는지를 확인하는 것임..!
// +) Array.includes() : 배열 속 어떤 값이 존재하는지 확인.
// [차이에 대한 자세한 설명: https://n-log.tistory.com/39]
function solution(cards1, cards2, goal) {
  let idx1 = 0,
    idx2 = 0;
  let len1 = cards1.length,
    len2 = cards2.length;

  for (let word of goal) {
    if (idx1 < len1 && word === cards1[idx1]) idx1++;
    else if (idx2 < len2 && word === cards2[idx2]) idx2++;
    else return "No";
  }
  return "Yes";
}

// 외
// 효율성 측면에서는 shift보다 index로 순회하는 것이 낫다고 한다ㅏ! 켈켈
function solution(cards1, cards2, goal) {
  for (const s of goal) {
    if (cards1[0] == s) {
      cards1.shift();
    } else if (cards2[0] == s) {
      cards2.shift();
    } else {
      return "No";
    }
  }
  return "Yes";
}
