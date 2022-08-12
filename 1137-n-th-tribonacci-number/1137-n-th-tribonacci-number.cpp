class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;
        int a1=0,a2=1,a3=1,ans;
        for(int i=3;i<=n;i++){
            ans=a1+a2+a3;
            a1=a2;
            a2=a3;
            a3=ans;
        }
        return ans;
        
    }
};