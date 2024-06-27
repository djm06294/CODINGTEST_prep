// 여러개 전화번호 중 다른 전화번호의 prefix가 있는지 확인하고 있으면 false 있으면 true 반환

// 주영
function solution(phone_book) {
    var N = phone_book.length;
    var minLen = phone_book[0].length;
    var map = new Map();
    phone_book.sort(function comp(a,b) {
        if(a.length < b.length) return -1;
        else return 1;
    })
    
    console.log(phone_book)
    
    for(let i=1; i<N; i++) {
        let tmpLen = phone_book[i].length;
        if(tmpLen < minLen)
            minLen = tmpLen;
    }
    
    for(let i=0; i<N; i++) {
        let tmpStr = phone_book[i];
        let tmpLen = tmpStr.length;
        for(let j=minLen; j<tmpLen; j++) {
            if(map.has(tmpStr.substr(0,j))) 
                return false;     
        }
        map.set(tmpStr, 0);
    }
    
    return true;
}
// 계속 testcase 1개가 틀려서 뭘 놓쳤는지 지피티 물어봤다가 완전 간단한 답을 얻어버림...

// GPT
// 숫자 string을 알파벳순서 처럼 정렬하면 각 원소 앞뒤가 서로 prefix인지만 확인해주면 해결된다는 신기한 사실...!
function solution(phone_book) {
    // Step 1: Sort phone_book lexicographically
    phone_book.sort();
    
    // Step 2: Check each number with the next one in the sorted list
    for (let i = 0; i < phone_book.length - 1; i++) {
        if (phone_book[i + 1].startsWith(phone_book[i])) {
            return false;
        }
    }
    return true;
}

// 그 외
// 1. some함수 완전 꿀이잖아? 쓰임새를 익히자.
function solution(phoneBook) {
    return !phoneBook.sort().some((t,i)=> {
        if(i === phoneBook.length -1) return false;

        return phoneBook[i+1].startsWith(phoneBook[i]);      
    })
}

// 이해가 안감,,
function solution(phoneBook) {
    for (let number of phoneBook) {
        let reg = RegExp('^' + number);
        let count = phoneBook.filter(t => reg.test(t));
        if (count.length > 1) return false;
    }
    return true;
}