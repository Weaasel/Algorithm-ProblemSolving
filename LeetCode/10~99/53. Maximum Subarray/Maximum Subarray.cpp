class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = 0, res = nums[0];
        for(int n:nums) {
            res = max(res,last+n);
            last = max(0, last+n);
        }
        return res;
    }
};
