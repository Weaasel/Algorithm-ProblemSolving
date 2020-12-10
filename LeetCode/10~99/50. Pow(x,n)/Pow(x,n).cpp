class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0) return 1.0/myPow(x,-n);
        if(n == 0) return 1.0;
        double tmp = myPow(x,n/2);
        if(n%2==0) return tmp*tmp;
        else return tmp*tmp*x;
    }
};
