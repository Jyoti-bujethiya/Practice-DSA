vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    vector<vector<int>>ans;
vector<int>temp;
int n=A.size();
for(int i=0;i<B.size();i++){
    temp=A;
    int x=B[i];
    x=x%n;
    rotate(temp.begin(),temp.begin()+x,temp.end());     //stl algo rotate
    ans.push_back(temp);
}
return ans;
}