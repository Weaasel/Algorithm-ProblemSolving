/*
  to increase n-1 elements by 1 == decrease 1 element by 1
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0];
        for(int n:nums) {
            mn = min(mn, n);
        }
        int sum = 0;
        for(int n:nums) {
            sum += n-mn;
        }
        return sum;
    }
};
