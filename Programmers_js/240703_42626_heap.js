// 모든 음식들이 K를 넘는 수를 가지도록 할때까지 정해진 계산을 하기. 정해진 계산은 음식들 중 최소값 두가지를 합해서 다시 음식들에 추가하는 것. 
// => 음식들 중 최솟값을 계속 계산해야한다는 점에서 heap을 사용하는 것이 좋다 판단!

// 주영
// 힙의 push, pop을 function으로 구현해주었음!
// 1. Math.max(a, b, c) 함수를 알게 되었다! (min도 가능)
function solution(scoville, K) {
    var answer = 0;
    var heap = [0];
    var len = scoville.length;
    
    for(let i=0; i<len; i++) {
        push(heap, scoville[i]);
    }
    
    while(heap[1]<K) {
        if(heap.length<3) return -1;
        let tmp = pop(heap) + 2*pop(heap);
        push(heap, tmp);
        answer++;
    }
    return answer;
}

function push(arr, num) {
    let len = arr.length-1;
    arr[len+1] = num;
    
    for(let i=len+1; i!=1;) {
        let i_ = Math.floor(i/2);
        if(arr[i] < arr[i_]) {
            let t = arr[i];
            arr[i] = arr[i_];
            arr[i_] = t;
            i=i_;
        } else {
            break;
        }
    }
}

function pop(arr) {
    let retVal = arr[1];
    let len = arr.length-1;
    arr[1] = arr[len];
    arr.pop();
    for(let i=1, i_; 2*i<len;) {
        if(arr[2*i]<arr[2*i+1] || arr[2*i+1]===undefined) i_=2*i;
        else  i_=2*i+1;
        
        if(arr[i]>arr[i_]) {
            let t = arr[i];
            arr[i] = arr[i_];
            arr[i_] = t;
            i=i_;
        } else {
            break;
        }
    }
    return retVal;
}

// 외
// 체계적으로 민힙을 잘 구현하여 사용하신듯! solution 함수는 간단하심.
// 1. swap 쉽게 하기 : [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]]
// 2. foreach함수 : arr의 모든 값에 대해 함수를 실행시켜 저장한다.
//                  ex) arr.forEach(function(n){ ... })
//                  ex) arr.forEach(n=>{ ... })
class MinHeap {
    constructor() {
        this.heap = [];
    }

    size() {
        return this.heap.length;
    }

    swap(idx1, idx2){
        [this.heap[idx1], this.heap[idx2]] = [this.heap[idx2], this.heap[idx1]];
        return this.heap;
    }

    getParentIdx(childIdx){
        return Math.floor((childIdx-1) / 2);
    }

    getLeftChildIdx(parentIdx){
        return parentIdx*2 + 1;
    }

    getRightChildIdx(parentIdx){
        return parentIdx*2 + 2;
    }

    heappop(){
        const heapSize = this.size();
        if (!heapSize) return null;
        if (heapSize === 1) return this.heap.pop();

        const value = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbledown();
        return value;
    }

    heappush(value){
        this.heap.push(value);
        this.bubbleup();

        return this.heap;
    }

    bubbleup() {
        let child = this.size()-1;
        let parent = this.getParentIdx(child);

        while(this.heap[child] < this.heap[parent]){
            this.swap(child, parent);
            child = parent;
            parent = this.getParentIdx(parent);
        }
    }

    bubbledown() {
        let parent = 0;
        let leftChild = this.getLeftChildIdx(parent);
        let rightChild = this.getRightChildIdx(parent);

        while((leftChild <= this.size()-1 && this.heap[leftChild] < this.heap[parent]) || (rightChild <= this.size()-1 && this.heap[rightChild] < this.heap[parent])){

            if (rightChild <= this.size()-1 && this.heap[leftChild] > this.heap[rightChild]){
                this.swap(parent, rightChild);
                parent = rightChild;
            }else {
                this.swap(parent, leftChild);
                parent = leftChild;
            }
            leftChild = this.getLeftChildIdx(parent);
            rightChild = this.getRightChildIdx(parent);
        }     
    }
}

function solution(scoville, K) {
    let count = 0;
    const heap = new MinHeap();
    scoville.forEach(el => heap.heappush(el));

    while(heap.heap[0] < K && heap.size() > 1){
        count++;
        heap.heappush(heap.heappop() + heap.heappop()*2);
    }
    return heap.heap[0] >= K ? count : -1;
}