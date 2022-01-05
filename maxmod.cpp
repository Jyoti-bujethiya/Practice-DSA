/*Given an array A of size N, groot wants you to pick 2 indices i and j such that

1 <= i, j <= N
A[i] % A[j] is maximum among all possible pairs of (i, j).
Help Groot in finding the maximum value of A[i] % A[j] for some i, j.*/

int getMaxValue(int arr[], int arr_size)
{
    int i, first, second;
 
    // There must be at least two elements
    if (arr_size < 2) {
        return 0;
    }
 
    // To store the maximum and the second
    // maximum element from the array
    first = second = INT_MIN;
    for (i = 0; i < arr_size; i++) {
 
        // If current element is greater than first
        // then update both first and second
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
 
        // If arr[i] is in between first and
        // second then update second
        else if (arr[i] > second && arr[i] != first)
            second = arr[i];
    }
 
    // No second maximum found
    if (second == INT_MIN)
        return 0;
    else
        return second;
}
 