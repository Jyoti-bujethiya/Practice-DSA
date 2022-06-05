// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool issafe(vector<vector<int>> arr,int x,int y,int n){
       //check for row  
       for(int row=0;row<x;row++)
           if(arr[row][y]==1) return false;
   
       //check left diagonal    
       int row=x;
       int col=y;
       while(row >=0 && col>=0){
           if(arr[row][col]==1) return false;
           row--;
           col--;
       }
   
       //check uper right diagonal 
       row=x;
       col=y;
       while(row >=0 && col<n){
           if(arr[row][col]==1) return false;
           row--;
           col++;
       }
   
       // return true it means that block are safe to plase till
       return true;
   }
   void nqueen(vector<vector<int>> &board,int x,int n,vector<vector<int>> &ans){
       //all queen are set in board
       if(x==n){
           vector<int> temp;
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(board[i][j]!=0){
                       temp.push_back(j+1);
                   }
               }
           }
           ans.push_back(temp);
           return;
       }
   
       for(int i=0;i<n;i++){
           if(issafe(board,x,i,n)){
               board[x][i]=1;
               nqueen(board,x+1,n,ans);
               board[x][i]=0;
           }
       }
   }
   vector<vector<int>> nQueen(int n) {
       // code here
       vector<vector<int>> ans;
       vector<vector<int>> board(n,vector<int>(n));
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               board[i][j]=0;
           }
       }

       nqueen(board,0,n,ans);
       
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends