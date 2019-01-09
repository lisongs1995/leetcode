static const auto __ = [](){ios::sync_with_stdio(false);cin.tie(0);return 0;};
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int ans = 0, tmp = x;
        while(tmp!=0){
            ans = ans * 10 + tmp % 10;
            tmp /= 10;
        }
        return x == ans;
    }
};
