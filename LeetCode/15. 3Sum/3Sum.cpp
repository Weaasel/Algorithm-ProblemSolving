#define pb push_back
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for(int i=0;i<sz;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int w1 = i+1, w2=sz-1;
            while(w1<w2) {
                if(nums[i] + nums[w1] + nums[w2] == 0) {
                    vector<int> v;
                    v.pb(nums[i]);
                    v.pb(nums[w1]);
                    v.pb(nums[w2]);
                    sort(v.begin(), v.end());
                    res.pb(v);
                    w1++;
                    while(w1<w2 && nums[w1 - 1] == nums[w1])w1++;
                }
                else if(nums[i] + nums[w1] + nums[w2] < 0) {
                    w1++;
                }
                else {
                    w2--;
                }
            }
        }
        return res;
    }
};
