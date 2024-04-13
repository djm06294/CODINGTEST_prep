// 24.02.07 WED
// JOOYOUNG KIM
// https://leetcode.com/problems/unique-morse-code-words/description/

// worst code.. 머리 안돌아감
// 중복안되는 자료구조 사용하면 바로 해결 됨.
// map을 사용해볼 수 있어서 좋았다.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, string> morse = {{'a',".-"}, {'b',"-..."}, {'c',"-.-."}, {'d',"-.."}, {'e',"."}, {'f',"..-."}, {'g',"--."}, {'h',"...."}, {'i',".."}, {'j',".---"}, {'k',"-.-"}, {'l',".-.."}, {'m',"--"}, {'n',"-."}, {'o',"---"}, {'p',".--."}, {'q',"--.-"}, {'r',".-."}, {'s',"..."}, {'t',"-"}, {'u',"..-"}, {'v',"...-"}, {'w',".--"}, {'x',"-..-"}, {'y',"-.--"}, {'z',"--.."}};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int count=0;
        vector<string> morseWords;

        for(auto s:words) {
            string tmp;
            for(auto c:s) {
                tmp += morse[c];
                
            }
            cout<<"tmp"<<tmp<<endl;

            for(auto m:morseWords) {
                if(m==tmp) count--;
                cout<<"cnt"<<count<<endl;
            }
            morseWords.push_back(tmp);
            count++;
        }
        return count;
    }
};