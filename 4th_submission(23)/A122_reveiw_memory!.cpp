// 문제: string s를 shift 해서 goal을 만들어 낼 수 있는지 확인하기.

// 정말로 string 내에서 한칸한칸 옆으로 옮겨서 shift를 해가며 확인해주었다.
#include <string>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        for(int i=0;i<s.size();i++){
            if(s==goal){
                return true;
            }
            char temp=s[0];
            for(int j=0;j<s.size();j++){
                s[j]=s[j+1];
            }
            s[s.size()-1]=temp;
        }
        return false;
    }
};


// 두 string의 길이가 같은지 && goal에서 s+s를 찾아서 존재하는지
// 이 두가지 조건이 만족하는지를 보면 되나보다! 신기하다. 짧다.

class Solution {
 public:
  bool rotateString(string s, string goal) {
    return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    cout<<"Ankita Sharma_21BCS2219";
  }
};