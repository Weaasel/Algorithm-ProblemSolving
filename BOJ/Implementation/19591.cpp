//독특한 계산기
//Implementation, Deque
/*
  전체 연산식의 앞뒤를 보며 값이 더 커지는 연산으로 하나씩 수행하는 문제이다.
  지문 그대로 구현하기 위해 deque 자료구조를 사용하고,
  숫자와 연산자를 따로 관리하면 구현이 편다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define INF 1e18
#define DIV 1000000007
const int mxn = 500001;

using namespace std;

string str;
int wlk;
int sz;
int val[250];
deque<ll> numdq;
deque<char> opdq;

ll readnum() {
	while (str[wlk] == '0') wlk++;
	ll ret = 0;
	while (str[wlk] >= '0' && str[wlk] <= '9') {
		ret *= 10;
		ret += str[wlk] - '0';
		wlk++;
	}
	return ret;
}

ll readop() {
	wlk++;
	return str[wlk - 1];
}

ll operate(ll a, ll b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	val['+'] = 1;
	val['-'] = 1;
	val['*'] = 2;
	val['/'] = 2;

	cin >> str;
	sz = str.size();
	if (str[wlk] == '-') {
		wlk++;
		ll nn = readnum();
		numdq.pb(-nn);
	}
	else {
		ll nn = readnum();
		numdq.pb(nn);
	}

	while (wlk < sz) {
		char op = readop();
		opdq.pb(op);
		ll nn = readnum();
		numdq.pb(nn);
	}
	int numsz = numdq.size();
	int opsz = opdq.size();

	if (numsz == 1) {
		cout << numdq.front();
		return 0;
	}
	while (!opdq.empty()) {
		if (numsz == 2) {
			cout << operate(numdq.front(), numdq.back(), opdq.front());
			break;
		}
		ll n1 = numdq.front(), n2, n3 = numdq.back(), n4;
		numdq.pop_front();
		numdq.pop_back();
		n2 = numdq.front();
		n4 = numdq.back();

		char op1 = opdq.front(), op2 = opdq.back();
		if (val[op1] > val[op2]) { //op1실행
			ll nn = operate(n1, n2, op1);
			numdq.pop_front();
			numdq.push_front(nn);
			numdq.pb(n3);
			opdq.pop_front();
		}
		else if (val[op2] > val[op1]) { //op2실행
			ll nn = operate(n4, n3, op2);
			numdq.pop_back();
			numdq.push_back(nn);
			numdq.push_front(n1);
			opdq.pop_back();
		}
		else {
			ll cand1 = operate(n1, n2, op1);
			ll cand2 = operate(n4, n3, op2);
			if (cand1 >= cand2) {
				ll nn = operate(n1, n2, op1);
				numdq.pop_front();
				numdq.push_front(nn);
				numdq.pb(n3);
				opdq.pop_front();

			}
			else {
				ll nn = operate(n4, n3, op2);
				numdq.pop_back();
				numdq.push_back(nn);
				numdq.push_front(n1);
				opdq.pop_back();
			}
		}
		numsz--;
		opsz--;
	}

	return 0;
}
