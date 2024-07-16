// 여러번 눌러서 원하는 문자를 출력할 수 있는 여러가지 키가 주어졌을 때, 주어진 문자열을 입력하기 위해 키를 눌러야하는 최소값 구하기. (불가능하다면 -1 반환)

// 주영
// 사용해보고 싶었던 여러가지 함수를 활용해볼 수 있어서 좋았다! 아직 헷갈리는데, 익숙해지려면 더 많이 써봐야겠다.
// 1. Array.map()
// 2. Array.indexOf() : 괄호 안의 요소를 Array에서 찾아 인덱스 반환. 존재하지 않으면 -1 반환.
// 3. Array.filter() : Array의 요소를 괄호 안의 콜백함수로 걸러서 남은 요소들 담은 배열 반환.
// 4. Math.min.apply(null, [~]) : Math.min을 배열에 적용하기 위해 apply를 사용함. 첫번째 parameter는 무엇인지 아직 모름..!
// + Math.min에 빈비열을 넣으면 반환값으로 infinity를 반환.
function solution(keymap, targets) {
  var answer = [];

  answer = targets.map((str) => {
    let str_len = str.length;
    let count = 0;

    for (let i = 0; i < str_len; i++) {
      let push_counts = keymap
        .map((v) => v.indexOf(str[i]))
        .filter((n) => n != -1);
      if (push_counts.length == 0) return -1; // 입력 불가할 경우 -1 반환

      count += Math.min.apply(null, push_counts) + 1;
    }
    return count;
  });

  return answer;
}

// 외
// 1. String.split(separator, limit) : string에서 separator을 찾아서 그걸 기준으로 끊어 각 string을 배열로 반환. limit은 최대 반환 배열의 개수. 개수가 다 차면 더 이상 자르지 않음. separator가 주어지지 않을 경우 string 그대로 반환.
// 2. Array.reduce(accumulator, callback, initVal) : accumulator에 initVal 또는 Array의 첫 요소가 들어가서 시작, callback 함수를 모든 요소에 대해 진행한 수 accumulator값 반환.
function solution(keymap, targets) {
  const answer = [];
  const map = {};
  for (const items of keymap) {
    items.split("").map(
      (item, index) =>
        (map[item] = map[item] < index + 1 ? map[item] : index + 1) // 각 알파벳에 대한 최솟값 찾아서 저장.
    );
  }
  for (const items of targets) {
    answer.push(
      items.split("").reduce((cur, item) => (cur += map[item]), 0) || -1
    );
  }
  return answer;
}

// 나처럼 min에 넣기 전에 빈배열인지 확인해주는 방법 말고 그냥 infinity인지 확인해주는 방법도 있군!
function solution(keymap, targets) {
  const answer = [];

  for (let i of targets) {
    let sum = 0;
    for (let j of i) {
      let idxArr = keymap.map((v) => v.split("").indexOf(j) + 1 || Infinity);
      sum += Math.min(...idxArr);
    }
    sum = sum === Infinity ? -1 : sum;
    answer.push(sum);
  }
  return answer.includes(Infinity) ? -1 : answer;
}
