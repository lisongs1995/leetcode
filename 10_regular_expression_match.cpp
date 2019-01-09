static const auto __ = [](){ios::sync_with_stdio(false); cin.tie(0);return 0;};
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        bool dp[m+1][n+1];
        dp[0][0] = true;
        for(int i=1; i<m+1; i++)
            dp[i][0] = false;
        for(int j=1; j<n+1; j++)
            if(j>1 && p[j-1]=='*')
                dp[0][j] = dp[0][j-2];
            else
                dp[0][j] = false;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(j>1 && p[j-1] == '*'){
                    if(p[j-2] == '.' || s[i-1] == p[j-2])
                        dp[i][j] = dp[i][j-2]||dp[i-1][j-1] || dp[i-1][j]; //匹配0个 || 匹配1个 || 匹配多个
                    else
                        dp[i][j] = dp[i][j-2]; // 匹配0个
                }
                else
                    dp[i][j] = false;
            }
        }

        return dp[m][n];
    }
};
