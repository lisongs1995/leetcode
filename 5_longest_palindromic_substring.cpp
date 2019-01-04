#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static string longestPalindrome(string s) {
        int size = s.size();
        if(size<=1)
            return s;
        int begin=0, length=1;
        for(string::size_type i=0; i<size; i++){
            if(length/2 > size-i){
                break;
            }
            int j=i,k=i;
            while(k<size-1 && s[k] == s[k+1]) k++;
            while(j>0 && k<size-1 && s[j-1] == s[k+1]){
                
                cout << "s[j-1]=" << s[j-1] << " s[k+1]=" << s[k+1] <<endl; 
                j--;
                k++;
            }
            if(length < k-j+1){
                length = k-j+1;
                begin = j;
            }
        }
        return s.substr(begin, length);
    }
};

int main(){
    string test = "ababababa";
    cout << Solution::longestPalindrome(test) << endl;
}
