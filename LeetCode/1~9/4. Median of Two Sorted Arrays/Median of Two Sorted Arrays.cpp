class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), mid;
        if((m+n)%2==1) {
            mid = (m+n)/2;
        }
        else {
            mid = (m+n)/2-1;
        }
        vector<int> nums;
        int w1=0,w2=0;
        while(w1<m && w2<n) {
            if(nums1[w1] < nums2[w2]) nums.push_back(nums1[w1++]);
            else nums.push_back(nums2[w2++]);
        }
        while(w1<m) {
            nums.push_back(nums1[w1++]);
        }
        while(w2<n) {
            nums.push_back(nums2[w2++]);
        }
        double res;
        if((m+n)%2==1) {
            res = nums[mid];
        }
        else {
            res = (nums[mid] + nums[mid+1])/2.0;
        }
        return res;
    }
};
