//D - Phoenix and Science	
/*
  박테리아가 그 무게가 몇이건, 다음날이 되면 무게는 +1 증가한다.
  즉 전체 무게의 합이 얼마나 변하는가에는 박테리아의 개수만이 영향을 미치고,
  
  우리는 박테리아의 전체 무게(sum), 개수(k) 두가지를 유지하면 된다.
  처음엔 sum = 0, k = 1 에서 시작하여 sum이 n이 될 때까지 시뮬레이션하면 된다.
  다음날의 k는 (k ~ 2k) 가 될 수 있다.
  
  로직은 간단하다.
  하루가 시작하면 전체 무게는 전날보다 k개만큼 늘어날 것이다.(sum += k)
  
  1. 목표치인 n과의 차이가 2K 이하라면, 오늘 박테리아를 분열시켜서 내일 아침에 도달할 수 있으므로
     필요한 만큼을 분열시키고 loop를 break한다.
  
  2. 그게 아니라면 남은 무게의 절반, 즉 (n-sum)/2 이하 범위 안에서 될  수 있는 만큼 많이 분열시키는 것이 이득이다.
    만약 (n-sum)/2 초과로 k를 키우게 되면 내일모레 박테리아의 분열로 인해 전체 무게가 n을 초과하게 된다.
    
  이렇게 진행하면서 늘어나는 k만큼을 계속해서 저장해주고, 마지막에 함께 출력해준다.
  
  *만약 input n의 범위가 1도 포함했다면, if(n==1) cout<<0 이라는 예외처리가 필요했을 것 같다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

ll T, n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ll sum = 0, k = 1;
		int dist = 0;
		vector<ll> ans;
		while (1) {
			sum += k;
			if (n - sum <= 2 * k) {
				ans.pb(n - sum - k);
				dist++;
				break;
			}
			ll cnt = min(k, (n - sum) / 2 - k);
			ans.pb(cnt);
			k += cnt;
			dist++;
		}
		cout << dist << "\n";
		for (int a : ans) cout << a << " ";
		cout << "\n";
	}

	return 0;
}
