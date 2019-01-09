static const auto __ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;};
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <=numRows || numRows == 1)
            return s;
        vector<string> ans(numRows);
        int step = 1, runner=0;
        for(string::size_type i=0; i<s.size(); i++){
            // judge first, then act in your place
            ans[runner].push_back(s[i]);
            runner += step;
            if(runner == 0)
                step = 1;
            if(runner == numRows-1)
                step = -1;
            
        }
        string res;
        for(vector<string>::size_type i=0; i<ans.size(); i++)
            res += ans[i];
        return res;
    }
};
