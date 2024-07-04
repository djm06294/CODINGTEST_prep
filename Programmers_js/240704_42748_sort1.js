// 주어진 배열의 부분을 추출하여 sort한 후 몇번째 수를 구하기

// 주영
// 1. 왜 그냥 .sort()하면 통과가 안될까?
//      => ai 코드 피드백 : sort는 요소를 문자열로 변환 후에 유니코드 포인트의 순서로 비교 정렬한다고 한다. 그래서 따로 숫자를 계산하는 내장 함수를 넣어줘야 통과가 된다.
//      => 실제로 실험 결과 1, 11, 111, 13을 오름차순으로 정렬하면 변함이 없다. 따라서 문자열로 정렬을 한다고 생각할 수 있다.
function solution(array, commands) {
    var answer = [];
    var N = commands.length;

    for(let i=0; i<N; i++) {
        let part_arr = array.slice(commands[i][0]-1,commands[i][1]);
        part_arr.sort((a, b) => a - b);
        answer.push(part_arr[commands[i][2]-1]);
    }
    return answer;
}

// 외
// 1. Array의 map함수가 아직 익숙하지 않다. 아래에서는 commands의 각 요소인 command를 함수로 전달해서 그 함수에서 리턴하는 값들이 들어있는 array를 새로 생성하여 반환한다.
function solution(array, commands) {
    return commands.map(command => {
        const [sPosition, ePosition, position] = command
        const newArray = array
            .filter((value, fIndex) => fIndex >= sPosition - 1 && fIndex <= ePosition - 1)
            .sort((a,b) => a - b)    

        return newArray[position - 1]
    })
}

// 여기서도 commands의 각 요소를 v로 빼내서 각각 계산하므로 간단화한 게 보기 좋다.
function solution(array, commands) {
    return commands.map(v => {
        return array.slice(v[0] - 1, v[1]).sort((a, b) => a - b).slice(v[2] - 1, v[2])[0];
    });
}

// 결국 위와 같은 코드
var solution = (_, $) => $.map(([i,j,k]) => _.slice(i-1, j).sort((_,$) => _-$)[k-1])