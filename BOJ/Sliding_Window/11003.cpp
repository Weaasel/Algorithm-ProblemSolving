//최솟값 찾기
#include <stdio.h>
#include <deque>

using namespace std;
int arr[5000001];
deque<int> dq;
int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && dq.front() < i - l + 1) dq.pop_front();
		while (!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
		dq.push_back(i);
		printf("%d ", arr[dq.front()]);
	}
}
