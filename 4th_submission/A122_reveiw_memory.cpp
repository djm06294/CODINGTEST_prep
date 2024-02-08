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

class Solution {
 public:
  bool rotateString(string s, string goal) {
    return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    cout<<"Ankita Sharma_21BCS2219";
  }
};