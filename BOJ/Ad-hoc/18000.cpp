//One of each
//Ad-hoc, set, deque
/*
  앞에서부터 훑으며 부분수열을 만든다.
  이미 부분수열에 존재하는 원소는 건너뛴다.
  부분수열에 존재하는 원소는 넣을 것인데,
  
  수열의 뒤에서부터 보며
    1. 이번에 넣을 수보다 크고
    2. 뒤에도 그 수가 존재한다면(뒤에 넣어서 lexicographical smaller 달성 가능)
  뺀다. 이러한 원소들을 최대한 뺀 후에 부분수열에 append해준다.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#define pb push_back

using namespace std;

int n, k, a[202020];
int cnt[202020];
set<int> st;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	for (int i = 0; i < n; i++) {
		if (st.find(a[i]) == st.end()) {
			while (!dq.empty() && cnt[dq.back()] > 0 && dq.back() > a[i]) {
				int aa = dq.back();
				st.erase(aa);
				dq.pop_back();
			}
			st.insert(a[i]);
			dq.pb({ a[i]});
		}
		cnt[a[i]]--;
	}

	for (int r : dq) cout << r << " ";

	return 0;
}
