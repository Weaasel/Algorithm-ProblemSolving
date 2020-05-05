//C - Phoenix and Distribution
/*
  우선 k개의 partition이 모두 한 개 이상의 문자를 가져야 하므로,
  그들의 prefix를 전체 string s를 정렬한 상태에서 앞에서부터 k개로 채워줘야 한다.
  
  세 가지 경우로 나뉜다.
  1. 첫 prefix부터 lexiographical difference가 생기는 경우
    [a, a, b](k가 3) 등으로 나뉜다면, 그 뒤에 나오는 문자들은, lexiogrphical 더 작은 partition에 다 넣어주면 된다.
    
  2. 첫 문자들을 전부 나눠준 시점에서 한가지 문자만 남은 경우
    [a, a, a](k가 3) 으로 처음에 나뉘고, 남은 문자들이 전부 a이거나 전부 b 등 모두 같은 경우에는
    최대한 균등하게 나눠주면서 길이가 가장 길어지는 partition을 출력하면 된다.
    
  3. else
    나머지 경우에는 그냥 한쪽으로 전부 몰아주는것이 lexiographical minimize를 구하는 길이다.
    ex) abc 보다 abbc, abbc보다 abbbc 가 더 작다. 즉 어차피 뒤에 더 큰걸로 끝날거면 그 앞에것들도 다 몰아주는게 맞다.
  
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

int T, n, k, cnt;
char s[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		cin >> s;
		sort(s, s + n);

		if (s[0] != s[k - 1]) {
			cout << s[k - 1] << "\n"; continue;
		}
		if (s[k] == s[n - 1]) {
			cout << s[0];
			for (int i = 0; i < (n - k - 1) / k + 1; i++) cout << s[k];
			cout << "\n";
			continue;
		}
		cout << s[0];
		for (int i = k; i < n; i++) cout << s[i];
		cout << "\n";
	}
	return 0;
}
