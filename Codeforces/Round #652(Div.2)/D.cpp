//D - TediousLee	
//dp
/*
  RDB라는 구조를 만들어 나간다. 이 구조에서 노드는 총 3개의 state중 하나를 가진다.
  born : 막 생성된 노드(리프일 것이다).
  sec1 : 생성된지 1초가 지나 하나의 child를 생성한 노드
  sec2 : 생성된지 2초가 지나 2개의 child를 더 생산하여 claw 형태의 root가 된 노드(여기에서 더 변하지 않는다.)
  
  우선 각 level에서 저 3개의 state를 가지는 노드가 각각 몇개 있는지를 세어 나간다.
  우리는 아래 3개의 관계식을 얻을 수 있다.
  1. born[i] = born[i-1] + 2*sec1[i-1]
  2. sec1[i] = born[i-1]
  3. sec2[i] = sec1[i]
  참고로 여기서 sec2는 이번 레벨에서 처음 생성된 것의 개수만 세었다.
  각각의 식에 대한 이유는 각자 생각해 보기 바란다.
  
  이렇게 놓고 보면 i번째 level에서 추가된 claws는 sec2[i] 라는 사실을 알 수 있다.

  이제 i번째 상태에서 고를 수 있는 최대 claws를 dp[i]라고 하면,
  dp[i] = dp[i-3] + sec2[i] 라는 것을 알 수 있다.
  이유는 i-3번째에서 존재했던 노드들은 이미 dp[i-3]에서 고른 claws 들에 포함되는 노드들이기 때문에,
  i-2번째에서 처음 생성된 노드들을 root로 가지는 claws만이 dp[i]에서 추가될 수 있기 때문이다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9

const ll DIV = 1e9 + 7;

using namespace std;

ll T, n, k;
ll born[2000001], sec1[2000001], sec2[2000001];
ll dp[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	born[1] = 1;
	for (int i = 2; i <= 2000000; i++) {
		born[i] = (born[i - 1] + sec1[i - 1] * 2) % DIV;
		sec1[i] = born[i - 1] % DIV;
		sec2[i] = sec1[i - 1] % DIV;
	}
	for (int i = 3; i <= 2000000; i++) {
		dp[i] = (dp[i - 3] + sec2[i] * 4) % DIV;
	}

	while (T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
