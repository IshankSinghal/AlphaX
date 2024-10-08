class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1) return 1;
        if(n==1) return x;
        if(n==-1) return 1/x;

        if(n<0){
            n=abs(n);
            x=1/x;
        }

        double ans = 1.0;
        ans=myPow(x,n/2);
        if(n%2==0) return ans*ans;
        else return x*ans*ans;
    }
};