// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool all9s(string &str){
        for(auto c: str){
            if(c!='9'){
                return false;
            }
        }
        return true;
    }
    
    bool all0s(string &str, int start, int end){
        for(int i=start;i<end;i++){
            if(str[i]!='0'){
                return false;
            }
        }
        return true;
    }
    
    void REVERSE(string &str){
        reverse(str.begin(),str.end());
    }
    
    bool isPalindrome(string &S, int n){
        int i=0;
        int j=n-1;
        while(i<=j){
            if(S[i]!=S[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
	long long int closestPalindrome(long long int num){
	    string str=to_string(num);
	    int n=str.size();
	    
	    if(isPalindrome(str,n)==true){
	        return num;
	    }
        
        if(str.size()==1 || (str[0]=='1' && all0s(str,1,n)==true)){  // for numbers in range 1-9 or 100 1000 1000 etc
            return stoll(str)-1;
        }
        
        if(all9s(str)==true){  // All 9s , just add strNum+2
            return stoll(str)+2;
        }
        
        if(str[0]=='1' && str[n-1]=='1' && all0s(str,1,n-1)==true){  // 1001, 101, 11, 1000001, ....
            return stoll(str)-2;
        }
        
        string palindromeRootStr=str.substr(0,(n+1)/2);
        string left,right;
        
        right=palindromeRootStr;
        left=palindromeRootStr;
        REVERSE(right);
        right=right.substr(n%2);
        string MirrorLeftToRight=left+right;
        // cout<<"MirrorLeftToRight-> "<<MirrorLeftToRight<<endl;
        
        
        long long int IncrementedLeft=stoll(palindromeRootStr)+1;
        left=to_string(IncrementedLeft);
        right=to_string(IncrementedLeft);
        REVERSE(right);
        right=right.substr(n%2);
        string AddOneToLeftAndMirror=left+right;
        // cout<<"AddOneToLeftAndMirror-> "<<AddOneToLeftAndMirror<<endl;
        
        
        long long int DecrementedLeft=stoll(palindromeRootStr)-1;
        left=to_string(DecrementedLeft);
        right=to_string(DecrementedLeft);
        REVERSE(right);
        right=right.substr(n%2);
        string SubOneToLeftAndMirror=left+right;
        // cout<<"SubOneToLeftAndMirror-> "<<SubOneToLeftAndMirror<<endl<<endl;
        
        
        long long int JUST_MIRROR=stoll(MirrorLeftToRight);
        long long int ADD_ONE_MIRROR=stoll(AddOneToLeftAndMirror);
        long long int SUB_ONE_MIRROR=stoll(SubOneToLeftAndMirror);
        long long int ORIGINAL=stoll(str);
        
        int minDiff=INT_MAX;
        string res="";
        
        if(abs(ORIGINAL-JUST_MIRROR)<minDiff){ 
            res=MirrorLeftToRight;
            minDiff=abs(ORIGINAL-JUST_MIRROR);
        }
        if(abs(ORIGINAL-ADD_ONE_MIRROR)<minDiff){
            res=AddOneToLeftAndMirror;
            minDiff=abs(ORIGINAL-ADD_ONE_MIRROR);
        }
        if(abs(ORIGINAL-SUB_ONE_MIRROR)<minDiff){
            res=SubOneToLeftAndMirror;
            minDiff=abs(ORIGINAL-SUB_ONE_MIRROR);
        }
        
        if(abs(ORIGINAL-JUST_MIRROR)==minDiff && stoll(res)>JUST_MIRROR){
            res=MirrorLeftToRight;
        }
        if(abs(ORIGINAL-ADD_ONE_MIRROR)==minDiff && stoll(res)>ADD_ONE_MIRROR){
            res=AddOneToLeftAndMirror;
        }
        if(abs(ORIGINAL-SUB_ONE_MIRROR)==minDiff && stoll(res)>SUB_ONE_MIRROR){
            res=SubOneToLeftAndMirror;
        }
        
        return stoll(res);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends