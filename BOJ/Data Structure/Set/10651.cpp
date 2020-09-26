//Cow Jog
//Greedy, Set
/*
  말들을 {시작점, 도착점} 으로 표현하자.
  시작점 기준으로 정렬해 두면
  말들이 중간에 만나지 않을 필요충분조건은 [늦게 출발한 말의 도착점 > 일찍 출발한 말의 도착점] 임을 알 수 있다.
  말은 일정한 속도로 달리기 때문이다.
  
  따라서 greedy하게 접근하면, 강의실 배정 문제와 닮아 있는 것을 알 수 있는데,
  일찍 시작하는 말부터 훑으면서 이번 말을 넣을 레인은
  "이번 말보다 앞에 있는 도착점 중 가장 늦게 도착하는 레인" 이 최적이다.
  이런 원소는 set의 lower_bound를 이용해 찾을 수 있다.
*/

#include <iostream>
#include <set>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

int n;
ll cur, t;
pll h[100010];
multiset<ll> ms;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> h[i].first >> h[i].second;
		h[i].second = h[i].second*t + h[i].first;
	}
	sort(h, h + n);
	for (int i = 0; i < n; i++) {
		auto it = ms.lower_bound(h[i].second);
		if (it != ms.begin()) {
			it--;
			ms.erase(it);
		}
		ms.insert(h[i].second);
	}
	cout << ms.size();
	return 0;
}
