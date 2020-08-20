#define pii pair<int, int>
#define pb push_back
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int res = 0;
        vector<pii> v;
        priority_queue<pii> pq_l, pq_r;
        
        for(int i = 0; i<sz;i++) {
            v.pb({height[i], i});
            pq_l.push({-i, height[i]});
            pq_r.push({i, height[i]});
        }
        sort(v.begin(), v.end());
        for(pii p:v) {
            int h = p.first, idx = p.second;
            while(!pq_l.empty() && pq_l.top().second < h) pq_l.pop();
            while(!pq_r.empty() && pq_r.top().second < h) pq_r.pop();
            if(!pq_l.empty()) res = max(res, h*abs(pq_l.top().first + idx));
            if(!pq_r.empty()) res = max(res, h*abs(pq_r.top().first - idx));
        }
        return res;
    }
};
