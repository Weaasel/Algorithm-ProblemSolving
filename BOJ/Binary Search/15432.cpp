//Suspension Bridges
//Binary search, Mathematics

/*
  주어진 식의 값이 monotone increase 하다는 것을 수학적으로 증명하고,
  해당 값을 찾기 위해 binary search 하는 
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
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 1e9
#define epsilon 1e-9
using namespace std;

double hs(double x) {
	return (exp(x) - exp(-x)) / 2.0;
}
double hc(double x) {
	return (exp(x) + exp(-x)) / 2.0;
}

double f(double a, double d) {
	return 2.0 * a * hs(d / (2.0 * a));
}

double left(double a, double s) {
	return a + s;
}
double right(double a, double d) {
	return a * hc(d / (2.0 * a));
}

double d, s;

int main() {
	cin >> d >> s;

	double l = epsilon, r = INF, mid, ll, rr;
	while (r - l >= epsilon) {
		mid = (l + r) / 2;
		ll = left(mid, s), rr = right(mid, d);
		if (abs(ll - rr) <= epsilon) {
			l = mid;
			break;
		}
		else if (ll > rr) r = mid - epsilon;
		else l = mid + epsilon;
	}
	printf("%.10lf", f(l, d));
	return 0;
}
