#include <bits/stdc++.h>
#include "package.h"
class Solution{
    public:
        int numDistinct(string s, string t){
            if(s.size()==0 && t.size()==0)
                return 1;
            if(s.size()!=0 && t.size()==0)
                return 1;
            if(s.size()==0 && t.size()!=0)
                return 0;
            if(s[s.size()-1] == t[t.size()-1])
            return numDistinct(s.substr(0, s.size()-1), t.substr(0, t.size()-1))+
                numDistinct(s.substr(0,s.size()-1), t);
            else
                return numDistinct(s.substr(0, s.size()-1), t)
        }
        int numDistinct(string s, string t){
            int dp[s.size()+1][t.size()+1];
            for(int i=0; i<s.size()+1; i++)
                dp[i][0] = 1;
            for(int i=1; i<t.size()+1; i++)
                dp[0][i] = 0;
            for(int i=1; i<s.size()+1; i++)
                for(int j=1; j<t.size()+1; j++){
                    if(s[i-1] == t[j-1])
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j-1];
                }
            return dp[s.size()][t.size()];
        }
};
