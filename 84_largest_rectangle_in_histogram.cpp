#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        v.push_back(0); // 防止再算一遍
        stack<int> st;
        int maxArea = 0, h, w;
        for (int i = 0; i < v.size(); i++) {
            if (st.empty() || v[i] >= v[st.top()]) st.push(i);
            else {
                while (!st.empty() && v[i] < v[st.top()]) {
                    h = v[st.top()];
                    st.pop();
                    w = st.empty() ? i : i - (st.top() + 1);
                    maxArea = max(h * w ,maxArea);
                }
                st.push(i);
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        if (v.empty()) return 0;
        int maxArea = 0, n = v.size();
        vector<int> left(n, 0), right(n, 0);

        right[n-1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > v[i+1]) right[i] = 1;
            else {
                int j = i + 1;
                while (j < n && v[j] <= v[i]) j += right[j];
                right[i] = j - i;
            }
        }

        left[0] = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] > v[i-1]) left[i] = 1;
            else {
                int j = i - 1;
                while (j >= 0 && v[j] <= v[i]) j -= left[j];
                left[i] = i - j;
            }
        }

        maxArea = v[0];
        for (int i = 0; i < v.size(); i++)
            maxArea = max((right[i] + left[i] - 1) * v[i], maxArea);
        return maxArea;
    }

};
