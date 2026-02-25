class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a||b||c){
            int aBit=a&1;
            int bBit=b&1;
            int cBit=c&1;
            if(aBit&&bBit){
                if(!cBit){
                    ans+=2;
                }
            }
            else if(aBit||bBit){
                if(!cBit){
                    ans++;
                }
            }else{
                if(cBit){
                    ans++;
                }
            }
            c=c>>1;
            a=a>>1;
            b=b>>1;
        }
        return ans;
    }
};