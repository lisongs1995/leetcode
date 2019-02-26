class Solution {
public:
    string countAndSay(int n) {
        //意思是n为1的时候返回1
        //n为2的时候上一个数字是1读起来就是1个1 即11
        //n为3的时候上一个数字是11，读起来就是2个1返回21
        //n为4的时候上一个数字是21，读起来就是1个2,1个1即1211
        if (n == 1) return "1";
        string ans;
        string res = countAndSay(n-1);
        int j = 0;
        for(int i = 0; i < res.size(); ) {
            while (res[j] == res[i]) j++;
            ans.push_back(j-i+'0');
            ans.push_back(res[i]);
            i = j;
        }
        return ans;
    }
};
