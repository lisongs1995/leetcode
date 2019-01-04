#include <bits/stdc++.h>
using namespace std;

static const auto __ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0;};
class Solution {
private:
    int min(int r1, int r2){ // in& r = mid/2; error convert const int& to int&
       return r1<r2?r1:r2;
    }  
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int mid = size >> 1;
        if(size & 0x01)
            return findK(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), mid+1);
        return (findK(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), mid) + 
            findK(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), mid+1)) / 2.0;
    }
    int findK(vector<int>::iterator nums1, int size1, vector<int>::iterator nums2, int size2, int k){
       if(size1 < size2)
           return findK(nums2, size2, nums1, size1, k);
        if(size2 == 0)
            return nums1[k-1];
        if(k == 1)
            return min(nums1[0], nums2[0]);
        int pb = min(size2, k/2);
        int pa = k - pb;
        if(nums1[pa-1] == nums2[pb-1])
            return nums1[pa-1];
        if(nums1[pa-1]>nums2[pb-1])
            return findK(nums1, size1, nums2+pb, size2-pb, k-pb);
        else
            return findK(nums1+pa, size1-pa, nums2, size2, k-pa);
    }
};
int main(){
    vector<int> a = {1,2,5};
    vector<int> b = {3};
    Solution s;
    cout << s.findMedianSortedArrays(a, b) <<endl;
}
