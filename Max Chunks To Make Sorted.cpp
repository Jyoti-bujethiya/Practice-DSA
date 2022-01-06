/*Smallest leftmost possible chunk is smallest index at which A[0….i] contains all elements upto i.

We can check that if maximum of A[0…..i] is i, only then we can take it as a seperate chunk.

Find the smallest possible leftmost chunk using above idea and after that we can proceed similarily for the remaining part.*/

int Solution::solve(vector < int > & A) {
    int cnt = 0, ma = 0, i = 0;
    for (auto x: A) {
        ma = max(ma, x);
        if (ma == i)
            cnt += 1;
        i += 1;
    }
    return cnt;
}