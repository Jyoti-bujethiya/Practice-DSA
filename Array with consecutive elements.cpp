/*We can simply check that, if we sort the array in increasing order the prev element should be one less than the current element.

If this condition satisfies for whole array then we return 1 else return 0.

NOTE: It is not necessary that array should start with 1.*/

int Solution::solve(vector < int > & A) {
    int n = A.size();
    int prev;
    //Sort the given array
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++) {
        if (i == 0)
            prev = A[i];
        else if (A[i] != prev + 1)
            return 0;
        prev = A[i];
    }
    return 1;
}

/*method 2
if elements are consecutive, they will form ap, find min ele that will be a, d=1,find sum of array ele, find sum of ap using formula, compare them.*/

 long len = A.size();

        int min = INT_MAX;

        long sum = 0;

        for(int i = 0; i < len; i++){

            min = min(min, A[i]);

            sum += A[i];

        }

        /* using AP formulae calculate sum of n integers 

            N/2[2a+(N-1)d]

        */

        long expected = ((len * ((min<<1) + (len - 1))*1 )>>1);

        return (expected == sum) ? 1:0;