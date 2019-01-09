#include <algorithm>
// bool cmp(const string& a, const string& b){
//     return a < b;
// }
static const auto __ = [](){ios::sync_with_stdio(false); cin.tie(0); return 0;};
int min(int r1, int r2){
    return r1<r2?r1:r2;
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size()==0)
            return ans;
        if(strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string second = strs[strs.size()-1];
        int i=0,size = min(first.size(), second.size());
        while(i < size){
            if(first[i] != second[i])
                break;
            i++;
        }
        ans = first.substr(0, i);
        return ans;
    }
};
