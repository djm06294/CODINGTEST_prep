// 순서대로 배포되야하는 여러 작업들의 진행률과 진행속도률/일 이 순서대로 저장된 배열 두개가 주어진다. 이때 한번에 배포될 수 있는 작업들의 개수를 순서대로 담은 배열을 반환하라.

// 주영
// stack이나 queue를 사용한건지 모르겠다.. 확인!
function solution(p, s) {
    var answer = [];
    var N = p.length;
    var key=Math.ceil((100-p[0])/s[0]);;
    var count=1;

    for(let i=1; i<N; i++) {
        if(Math.ceil((100-p[i])/s[i]) <= key) {
            count++
        } else {
            key = Math.ceil((100-p[i])/s[i]);
            answer.push(count);
            count=1;
        }
    }
    answer.push(count);    

    return answer;
}

// 외
// Array.map() 메소드에 대해 더 알아보자!
function solution(progresses, speeds) {
    let answer = [0];
    let days = progresses.map((progress, index) => Math.ceil((100 - progress) / speeds[index]));
    let maxDay = days[0];

    for(let i = 0, j = 0; i< days.length; i++){
        if(days[i] <= maxDay) {
            answer[j] += 1;
        } else {
            maxDay = days[i];
            answer[++j] = 1;
        }
    }

    return answer;
}

// 오 알고리즘 자체가 다르다. 하루하루 progress를 증가시키며 확인해주는 방식이군.
function solution(progresses, speeds) {
    var answer = [];

    while(speeds.length > 0) {
        // 개발
        for(let i in speeds) {
            if(progresses[i] < 100) {
                progresses[i] += speeds[i];
            }
        }

        // 배포
        let deploy_count = 0;
        while(progresses[0] >= 100) {
            progresses.shift();
            speeds.shift();
            deploy_count++;
        }
        if(deploy_count > 0) {
            answer.push(deploy_count);
        }
    }

    return answer;
}

// 속도가 빠르다고 한다.
function solution(progresses, speeds) {
    const length = progresses.length;
    let answer = [],
      i = 0,
      t = 0,
      numberOfReleases = 0;
  
    while (i < length) {
      numberOfReleases = 1;
      t = Math.ceil((100 - progresses[i]) / speeds[i++]);
  
      while (progresses[i] + speeds[i] * t > 99) {
        numberOfReleases++;
        i++;
      }
      answer.push(numberOfReleases);
    }
  
    return answer;
  }