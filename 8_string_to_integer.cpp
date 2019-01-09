class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int signal = 0;
        int pos = s.find_first_not_of(' ');
        //cout << pos << endl;
        for(int i=pos; i<s.size(); i++){
            if(s[i] == '-' || s[i] == '+'){
                if(signal)
                    break;
                signal = (s[i] == '-')?-1:1;
            }
            else if(isdigit(s[i])){
                signal = (signal==0)?1:signal;
                ans = ans*10 + s[i] - '0';
                if(signal*ans>=INT_MAX) return INT_MAX;
                if(signal*ans<=INT_MIN)  return INT_MIN;
               
            }
            else 
                break;
        }
        
        return signal*ans;
    }
};
