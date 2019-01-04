#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size <= 1)
            return size;
        int maxsize, start;
        maxsize = start = 0;
        vector<int> dict(256, -1);
        for(string::size_type i=0; i<size; i++){
            int key = s[i];
            if(dict[key]>=0 && dict[key]>=start){
                start = dict[key] + 1;
            }

            maxsize = (maxsize > i-start+1) ? maxsize:i-start+1;
            dict[key] = i;
        }
        return maxsize;
    }
};

int main(){
    string test = "abcabcbb";
    Solution s;
    cout << s.lengthOfLongestSubstring(test) << endl; 
}
