// 우선순위가 높은 일부터 처리한다고 할때 주어진 인덱스의 일은 몇번째로 수행하는지 구하기. (실행되지 않은 일은 queue의 끝으로 들어감)

// 주영
// queue를 구현할까 했지만 그렇게까지 안해도 풀릴 것 같아 그냥 배열을 사용했다. 오히려 queue를 구현하여 풀려고 하면 내가 구해야하는 idx가 몇번째인지 계산하는 것이 헷갈릴 것 같았다,,,
// 가독성은 별로 안좋을 수 있다..
function solution(priorities, location) {
    var answer = 0;
    var N = priorities.length;
    var min_sort = priorities.slice().sort(function(a,b){return b-a});  //내림차순 정렬(우선순위 순서대로 정렬)
    
    for(let i=0; i<N; ) {
        if(priorities[i] == min_sort[0]) {
            priorities.splice(i,1);
            min_sort.shift();
            answer++;
            
            if(i==location) return answer;
            if(i<location) location--;
            
            N = priorities.length;
        } else {
            i++;            
        }
        
        if(N==i) i=0;
    }
}


// 외
// map과 some을 사용하여 실제 queue 동작을 사용하여 구현했다... 천잰가
// js는 여러 처음보는 함수를 지원하는 것 같다. 학습 필요!!
function solution(priorities, location) {
    var list = priorities.map((t,i)=>({
        my : i === location,
        val : t
    }));
    var count = 0;        
    while(true){
        var cur = list.splice(0,1)[0];        
        if(list.some(t=> t.val > cur.val )){
            list.push(cur);                        
        }
        else{            
            count++;
            if(cur.my) return count;
        }
    }
}

// 위에 거랑 비슷하다.
function solution(priorities, location) {
    var arr = priorities.map((priority, index) => {
        return {
            index: index, priority: priority
        };
    });

    var queue = [];

    while(arr.length > 0) {
        var firstEle = arr.shift();
        var hasHighPriority = arr.some(ele => ele.priority > firstEle.priority);
        if (hasHighPriority) {
            arr.push(firstEle);
        } else {
            queue.push(firstEle);
        }
    }

    return queue.findIndex(queueEle => queueEle.index === location) + 1;
}


class Queue {
    constructor() {
        this.storage = {};
        this.front = 0;
        this.rear = 0;
    }

    size() {
        if(this.storage[rear] === undefined) return 0;
        else return this.rear - this.front + 1;
    }

    add(val) {
        if(this.size == 0) {
            this.storage['0'] = val;
        } else {
            this.rear += 1;
            this.storage[this.rear] = val;
        }
    }

    pop() {
        let tmp;
        if(this.front === this.rear) {
            tmp = this.storage[this.front];
            delete this.storage[this.front];
            this.front = 0;
            this.rear = 0;
        } else {
            tmp = this.storage[this.front];
            delete this.storage[this.front];
            this.front += 1;
        }
        return tmp;
    }
}

