// 0~9 사이의 숫자가 무작위로 담긴 배열에서 연속으로 나오는 숫자만 삭제한 배열 리턴하기. (연속이 아니라면 중복도 ok)

// 주영
// stack 근본 풀이인듯
// 와 진짜 로직에 문제가 없는데 자꾸 테스트 케이스 2개가 틀려서 골머리 앓았는데 != 냐 !== 냐의 문제였음. 모두 숫자일텐데 왜 차이가 있는거지? !==는 type까지 같은지를 확인하는거 아니였나????
function solution(arr)
{
    var answer = [];
    var N = arr.length;
    
    if(N != 0)
        answer.push(arr[0]);
    
    for(let i=1; i<N; i++) {
        if(arr[i-1] !== arr[i]) {
            answer.push(arr[i]);
        }
    }
    
    return answer;
}

// 외
// Array의 filter 함수: arr의 각 값, 인덱스, 그리고 arr 전체를 인수로 전달할 수 있다고 하고, 인수로 전달한 함수에 true를 반환하는 애들만 남겨놓는다. (good method!)
function solution(arr)
{
    return arr.filter((val,index) => val != arr[index+1]);
}

// 짧게 구현을 하셨지만 위와 원리는 비슷한 것 같다. 나중에 이해해보자.
let solution=_=>_.filter((i,$)=>i!=_[--$])