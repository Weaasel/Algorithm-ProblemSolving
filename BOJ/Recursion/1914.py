//하노이탑
/*
  하노이탑을 옮기는 방법은 우선 n-1층까지 옆층에 옮기고, 마지막 층을 목적지에 옮기고 n-1층을 다시한번 옮기는 것이다.
  답이 long long 범위를 넘을 수 있어 python으로 작성하면 편하다.
*/

def hn(n):
    if n==1:
        return 1
    else:
        return hn(n-1)*2+1

def hanoi(n, frm, tmp, to):
    if n==0: return
    hanoi(n - 1, frm, to, tmp)
    print(str(frm) + " " + str(to))
    hanoi(n - 1, tmp, frm, to)

n = int(input())
print(hn(n))
if n<=20:
    hanoi(n,1,2,3)
