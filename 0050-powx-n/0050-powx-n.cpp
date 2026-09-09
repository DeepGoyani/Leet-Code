class Solution {
    double help(double x,uint n){
        if(x==0)return 0;
        if(x==1||n==0)return 1;
        double halfPwr=help(x,n/2);
        if(n%2==0){
            return halfPwr*halfPwr;
        }
        return x*halfPwr*halfPwr;
        //if 2⁹ then 2*2⁴*2⁴ 
    }
public:
    double myPow(double x, int n) {
        bool negPwr=(n<0)?true:false;
        uint pwr=n;
        if(negPwr){
            pwr=-pwr;  
        }
        double ans=help(x,pwr);
        if(negPwr)return 1/ans;
        return ans;
    }
};