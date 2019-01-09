static const auto __ = [](){ios::sync_with_stdio(false); cin.tie(0); return 0;};
class Solution {
private:
    int min(int r1, int r2){
        return r1<r2?r1:r2;
    }
    int max(int r1, int r2){
        return r1>r2?r1:r2;
    }
public:
    int maxArea(vector<int>& h) {
        // slant 倾斜
        int i=0, j=h.size()-1;
        int v, maxV = 0;
        while(i<j){
            v = min(h[i],h[j]) * (j-i);
            maxV = max(maxV, v);
            if(h[i]>h[j])
                j--;
            else
                i++;
        }
        return maxV;
    }
};
