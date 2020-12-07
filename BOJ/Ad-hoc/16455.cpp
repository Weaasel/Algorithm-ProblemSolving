//K번째 수 찾는 함수
/*
  nth_element의 내부가 quick selection으로 구현되어 있어 이 연산을 O(n)에 수행할 수 있다고 한다.
*/

#include <bits/stdc++.h>
int kth(std::vector<int> &a, int k) {
    std::nth_element(a.begin(), a.begin() + (k-1), a.end());
  return a[k-1];
}
