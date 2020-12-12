/*
  독특한 유형의 완전탐색. 
  잘 짜자.
*/

class Solution {
public:
    vector<vector<int>> get(vector<int>& candidates, int idx, int target) {
        vector<vector<int>> res;
        if(target==0) {
            vector<int> r = {};
            res.push_back(r);
            return res;
        }
        else if(idx == candidates.size()) return res;
        for(int i=0;i<=target/candidates[idx];i++) {
            int nt = target - i*candidates[idx];
            vector<vector<int>> tmp = get(candidates, idx+1, nt);
            for(vector<int> v:tmp) {
                for(int j=0;j<i;j++) v.push_back(candidates[idx]);
                res.push_back(v);
            }
        }
        return res;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return get(candidates, 0, target);
    }
};
