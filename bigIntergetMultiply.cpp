#include <bits/stdc++.h>
using namespace std;

struct bigInteger{
    static int BASE=10;
    vector<int> data;
    bigInteger(long long val){
        do{
            data.push_back(val%BASE);
            val = val / BASE;
        }
        while(val>0);
        reverse(data.begin(), data.end());
    }
    bigInteger(string val){
        for(int i=0; i<val.size(); i++){
            data.push_back(val[i] - '0');
        }
    }
    bigInteger& operator+(bigInteger& tmp){
        vector<int> a = this->data;
        vector<int> b = tmp.data;
        int size = max(a.size(), b.size()) + 1;
        vector<int> ans(size);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0, carry=0;
        while(i++<size || carry){
            int first, second;
            if (i >= a.size())
                first = 0;
            if (i >= b.size())
                second = 0;
            int sum = first + second + carry;
            ans[i] = sum % BASE;
            carry = sum / BASE;
        }
        if(ans[size-1] == 0)
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        this->data = ans;
        return *this;
    }
    bigInteger& operator*(bigInteger& tmp){
        if(this->data.size()==0){
            this->data = tmp.data;
            return *this;
        }
        if(tmp.data.size() == 0)
            return *this;
        vector<int> a = this->data;
        vector<int> b = tmp.data;
        int length = a.size() + b.size();
        vector<int> ans(length, 0);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<a.size(); i++)
            for(int j=0; j<b.size(); j++){
                ans[i+j]+=(a[i]*b[j]);
        }
        for(int i=0; i<length-1; i++){
            int carry = ans[i] / 10;
            ans[i] = ans[i] % 10;
            ans[i+1] += carry;
        }
        if(ans[ans.size()-1] == 0)
            ans.pop_back();
        reverse(ans.begin(), ans.end());
       // for(int i=0; i<ans.size(); i++)
       //     cout << ans[i];
       // cout << endl;
        this->data = ans;
        return *this;
    }
    ofstream& operator<<(bigInteger& tmp){
        for(int i=0; i<tmp.data.size(); i++)
            ofstream << tmp.data[i];
        ofstream << endl;
    }
};

int main(){
    //vector<int> a = {2, 3, 3};
    //vector<int> b = {9, 2};
    vector<int> a = {2, 3, 3};
    vector<int> b = {1, 1};
    auto ans = a + b;
    for(int i=0; i<ans.size(); i++)
        cout << ans[i];
    cout << endl;
    
}
