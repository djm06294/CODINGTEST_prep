// 문제: 0과 자연수가 섞여있는 행렬에서 모든 0을 뒤로 보내기.

// 행렬의 첫 0의 인덱스를 찾아서 그 다음 수부터 0이 아닌 숫자와 저장된 인덱스의 숫자를 바꾸도록 구현함.

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        
        int n=a.size();
        int j=-1;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1){
            return;
        }
        for(int i=j+1;i<n;i++){
            if(a[i]!=0){
                swap(a[i],a[j]);
                    j++;
                }
            }
        }

             
    
};