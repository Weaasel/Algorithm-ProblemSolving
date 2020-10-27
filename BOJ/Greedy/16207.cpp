//직사각형
//Greedy
/*
  먼저 "쓸 수 있는 길이"를 정의하자.
  어떤 길이가 쓸 수 있으려면 해당 길이의 막대가 2개 존재하거나, 해당 길이보다 1 긴 길이의 막대가 존재해야 한다.
  이렇게 쓸수 있는 길이들을 최적으로 모으고 나면, 긴 길이들부터 매칭시켜서 직사각형을 구성하는 것이 넓이의 합을 최대화하는 길이다.
  
  쓸 수 있는 길이는 다음과 같이 선별한다.
    1. 막대를 내림차순으로 정렬한다.
    2. 앞에서부터 차례대로 보면서, stick[i] == stick[i+1] 이면 stick[i]를 쓴다.
       stick[i] == stick[i+1]+1 이면 i번째 막대의 길이를 1 줄이고 stick[i+1]을 쓴다.
       둘 다 해당되지 않으면 넘어간다.
  막대를 순서대로 보면서 다른 막대와 함께 사용할 수 있다면 사용하는 것이 무조건 좋다는 사실은 greedy하게 증명할 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;
int n;
vector<int> sticks;
ll solution() {
	ll res = 0;
	sort(sticks.begin(), sticks.end(), greater<int>());
	vector<ll> valid;
	for (int i = 0; i < n - 1;) {
		if (sticks[i] == sticks[i + 1]) {
			valid.push_back(sticks[i]);
			i += 2;
		}
		else if (sticks[i] == sticks[i + 1] + 1) {
			valid.push_back(sticks[i + 1]);
			i += 2;
		}
		else i++;
	}
	//valid에는 쓸 수 있는 길이들이 모여있음.
	int sz = valid.size();
	for (int i = 0; i < sz - 1; i += 2) {
		res += valid[i] * valid[i + 1];
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		sticks.push_back(s);
	}
	cout << solution();
	return 0;
}
