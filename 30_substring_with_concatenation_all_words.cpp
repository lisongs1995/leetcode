#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isSwap(vector<string>& words, int begin, int end){
        for(int i=begin; i<end; i++){
            if(words[i] == words[end])
                return false;
        }
        return true;
    }
    void swap(vector<string>& words, int i, int j){
        string tmp = words[i];
        words[i] = words[j];
        words[j] = tmp;
    }
    void dfs(int k, vector<string>& words, vector<string>& all_string){
        if(k == words.size()){
            string tmp;
            for(int i=0; i<words.size(); i++)
                tmp += words[i];
            all_string.push_back(tmp);
            return;
        }
        for(int i=k; i<words.size(); i++){
            if(isSwap(words, k, i)){
                swap(words, k, i);
                dfs(k+1, words, all_string);
                swap(words, k, i);
            }
        }
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty())
            return ans;
        vector<string> all_string;
        dfs(0, words, all_string);
        for(string ele: all_string){
            int idx = s.find(ele);
            if(idx!=-1)
                ans.push_back(idx);
        }
        return ans;
    }
};
int main(){
    string s1 = "barfoothefoobarman";
    vector<string> words1{"foo", "bar"};
    string s = "wordgoodgoodgoodbestword";
    vector<string> words{"word", "good", "best", "word"};
    vector<int> ans = Solution().findSubstring(s, words);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
