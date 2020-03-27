//C. Ternary XOR

#include <iostream>
#include <cstdio>
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int T, n, k;
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		vector<char> v(n), a(n), b(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		int flag = 1;
		a[0] = '1', b[0] = '1';
		for (int i = 1; i < n; i++) {
			if (v[i] == '0') {
				a[i] = '0', b[i] = '0';
			}
			else if (v[i] == '1') {
				if (flag) {
					a[i] = '1', b[i] = '0';
					flag = 0;
				}
				else {
					b[i] = '1', a[i] = '0';
				}
			}
			else if (v[i] == '2') {
				if (flag) {
					a[i] = '1', b[i] = '1';
				}
				else {
					b[i] = '2', a[i] = '0';
				}
			}
		}
		for (int i = 0; i < n; i++) cout << a[i];
		cout << "\n";
		for (int i = 0; i < n; i++) cout << b[i];
		cout << "\n";
	}
	return 0;
}
