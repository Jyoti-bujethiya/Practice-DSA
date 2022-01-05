
/*Initially sort the array.
For the minimum magic, find the sum of difference between adjacent elements in pairs of two.
For the maximum magic, find the sum of difference between the two elements equidistant from the front and back of the array.
*/
#define ll long long
#define mod 1000000007
vector < int > Solution::solve(vector < int > A) {
    int n = A.size();
    sort(A.begin(), A.end());
    ll mins = 0, maxs = 0;
    for (int i = 1; i < n; i += 2)
        mins += (ll)(A[i] - A[i - 1]);
    for (int i = 0; i < n / 2; i++)
        maxs += (ll)(A[n - 1 - i] - A[i]);
    vector < int > ans(2);
    ans[0] = maxs % mod;
    ans[1] = mins % mod;
    return ans;
}