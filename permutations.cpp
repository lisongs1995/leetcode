#include <bits/stdc++.h>
using namespace std;
void dfs(string& s, int k, int m){
    if(k==m){
        static int i=1;
        cout << "the " << i++ << " seq="
             <<  s << endl;
    }else{
        for(int i=k; i<=m; i++){
            swap(s[k], s[i]);
            dfs(s, k+1, m);
            swap(s[k], s[i]);
        }
    }
}
//这样我们也得到了在全排列中去掉重复的规则——去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换。
//用编程的话描述就是第i个数与第j个数交换时，要求[i,j)中没有与第j个数相等的数
bool isSwap(string& s, int begin, int end){
    for(int i=begin; i<end; i++)
        if(s[i]==s[end])
            return false;
    return true;
}
void dfs1(string&s, int k, int m){
    if(k==m){
        static int j=1;
        cout << "the " << j++ << " seq="
             <<  s << endl;
    }else{
        for(int i=k; i<=m; i++){
            if(isSwap(s, k, i)){
                swap(s[i], s[k]);
                dfs1(s, k+1, m);
                swap(s[i], s[k]);
            }
        }
    }

}
//   123  132 312
//


bool next_permutation(string& s){
    if(s.size()<2)
        return false;
    string::iterator end=s.end()-1;
    string::iterator p = end, q, find;
    while(p!=s.begin()){
        q = p;
        --p;
        if(*p < *q){
            cout << *p << endl;
            find = end;
            while(*find<=*p) --find;
            swap(*find, *p);
            reverse(q, s.end());
            return true;
        }
    }
    reverse(p, s.end());
    return false;
}
int main(){
    string s="abc"; // 123
    //dfs1(s, 0, s.size()-1);
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s));
    return 0;
}
