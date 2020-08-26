//2048 (Easy)
//Simulation

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

int Max = 0;
int table[21][21];
int copied[21][21];
queue<int> q;
int stackk[6] = { 0 };

void reset(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) copied[i][j] = table[i][j];
	}
}

void shiftup(int n) {
	for (int i = 1; i <= n; i++) {
		int j = 1, nextj = j+1;
		while (nextj <= n) {
			if (copied[nextj][i]==0) nextj++;
			else if (copied[nextj][i] != copied[j][i]) {
				j = nextj;
				nextj = j + 1;
			}
			else {
				copied[j][i] *= 2;
				copied[nextj][i] = 0;
				j = nextj + 1;
				nextj = j + 1;
			}
		}
		for (int k = 1; k <= n; k++) if (copied[k][i] != 0) q.push(copied[k][i]);
		j = 1;
		while (!q.empty()) {
			int tmp = q.front();
			copied[j][i] = tmp;
			q.pop();
			j++;
		}
		while (j <= n) {
			copied[j][i] = 0;
			j++;
		}
	}
}

void shiftdown(int n) {
	for (int i = 1; i <= n; i++) {
		int j = n, nextj = j - 1;
		while (nextj >= 1) {
			if (copied[nextj][i] == 0) nextj--;
			else if (copied[nextj][i] != copied[j][i]) {
				j = nextj;
				nextj = j - 1;
			}
			else {
				copied[j][i] *= 2;
				copied[nextj][i] = 0;
				j = nextj - 1;
				nextj = j - 1;
			}
		}
		for (int k = n; k >= 1; k--) if (copied[k][i] != 0) q.push(copied[k][i]);
		j = n;
		while (!q.empty()) {
			int tmp = q.front();
			copied[j][i] = tmp;
			q.pop();
			j--;
		}
		while (j >= 1) {
			copied[j][i] = 0;
			j--;
		}
	}
}

void shiftleft(int n) {
	for (int i = 1; i <= n; i++) {
		int j = 1, nextj = j + 1;
		while (nextj <= n) {
			if (copied[i][nextj] == 0) nextj++;
			else if (copied[i][nextj] != copied[i][j]) {
				j = nextj;
				nextj = j + 1;
			}
			else {
				copied[i][j] *= 2;
				copied[i][nextj] = 0;
				j = nextj + 1;
				nextj = j + 1;
			}
		}
		for (int k = 1; k <= n; k++) if (copied[i][k] != 0) q.push(copied[i][k]);
		j = 1;
		while (!q.empty()) {
			int tmp = q.front();
			copied[i][j] = tmp;
			q.pop();
			j++;
		}
		while (j <= n) {
			copied[i][j] = 0;
			j++;
		}
	}
}

void shiftright(int n) {
	for (int i = 1; i <= n; i++) {
		int j = n, nextj = j - 1;
		while (nextj >= 1) {
			if (copied[i][nextj] == 0) nextj--;
			else if (copied[i][nextj] != copied[i][j]) {
				j = nextj;
				nextj = j - 1;
			}
			else {
				copied[i][j] *= 2;
				copied[i][nextj] = 0;
				j = nextj - 1;
				nextj = j - 1;
			}
		}
		for (int k = n; k >= 1; k--) if (copied[i][k] != 0) q.push(copied[i][k]);
		j = n;
		while (!q.empty()) {
			int tmp = q.front();
			copied[i][j] = tmp;
			q.pop();
			j--;
		}
		while (j >= 1) {
			copied[i][j] = 0;
			j--;
		}
	}
}

void shift(int n, int pos) {
	switch (pos) {
	case 1: shiftup(n); break;
	case 2: shiftright(n); break;
	case 3: shiftdown(n); break;
	case 4: shiftleft(n); break;
	}
	return;
}

void func(int n, int num) {
	if (num == 6) {
		int localmax = 0;
		for (int i = 1; i < 6; i++) {
			shift(n, stackk[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (copied[i][j] > localmax) localmax = copied[i][j];
			}
		}
		if (localmax > Max) Max = localmax;
		reset(n);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		stackk[num] = i;
		func(n, num + 1);
		//stackk[num] = 0;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) scanf("%d", &table[i][j]);
	}
	func(n, 1);
	printf("%d", Max);
	return 0;
}
