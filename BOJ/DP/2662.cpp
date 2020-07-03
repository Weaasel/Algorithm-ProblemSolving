//기업 투자
//DP, knapsack problem
/*
  주어진 돈으로 최대의 효용을 요구하는 전형적인 knapsack문제이다.
  입력 범위도 작아서 어렵지 않게 생각할 수 있다.
  약간 까다로운 부분은 최대효용과 함께 자원의 분배도 출력해야 하는 점인데,
  그냥 dp 배열값을 vector로 만들어서 분배내용까지 저장해 버렸다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define ll long long
#define INF 2e9

using namespace std;

int n, m, idx;
vector<int> dp[21][301];
int w[21][301];

vector<int> go(int idx, int money) {
    vector<int> res(m+1);
    for(int i=0;i<=m;i++) res[i] = 0;
    if(idx==-1) return res;
    if(dp[idx][money].size() > 0) return dp[idx][money];
    for(int i=0;i<=money;i++) {
        vector<int> tmp = go(idx-1, money - i);
        if(res[0] < tmp[0] + w[idx][i]) {
            res = tmp;
            res[0] = tmp[0] + w[idx][i];
            res[idx + 1] = i;
        }
    }
    return dp[idx][money] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>idx;
        for(int j=0;j<m;j++) {
            cin>>w[j][idx];
        }
    }
    vector<int> v = go(m-1,n);
    cout<<v[0]<<"\n";
    for(int i=1;i<=m;i++) cout<<v[i]<<" ";
    return 0;
}
