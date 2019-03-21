#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> split(const string& str, const string& sep) {
    // 这个函数有一个问题就是split("/home/", "/") == >
    // vector("","home") 最后一个/ 不会放入
    if (sep.empty()) return {};
    string::size_type pos1 = 0, pos2 = str.find(sep);
    vector<string> ans;
    while (string::npos != pos2) {
        ans.push_back(str.substr(pos1, pos2 - pos1));
        pos1 = pos2  + sep.size();
        pos2 = str.find(sep, pos1);
    }
    if (pos1 != str.size())
        ans.push_back(str.substr(pos1));
    if (pos1 - sep.size() >= 0 && str.substr(pos1 - sep.size()) == sep)
        ans.push_back(string());
    return ans;
}
//int main() {
//    string str1 = "/home/";
//    vector<string> res = split(str1, "/");
//    for(string ele: res)  cout << ele << endl;
//    cout << res.size() << endl;
//
//}
