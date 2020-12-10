#include <bits/stdc++.h>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        set<int> s;
        int sz = nums.size();
        int res = 1e9, cand;
        s.insert(nums[0]+nums[1]);
        for(int i=2;i<sz;i++) {
            
            auto it = s.lower_bound(target - nums[i]);
            if(it!=s.end()) {
                cand = *it + nums[i];
                if(abs(target-cand) < abs(target-res)) res = cand;
            }
            if(it!=s.begin()) {
                it--;
                cand = *it + nums[i];
                if(abs(target-cand) < abs(target-res)) res = cand;                
            }
            
            for(int j=0;j<i;j++) s.insert(nums[j]+nums[i]);
        }
        return res;
    }
};
