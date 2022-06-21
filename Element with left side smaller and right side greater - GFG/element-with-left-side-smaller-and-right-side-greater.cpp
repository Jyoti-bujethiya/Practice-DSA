// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int a[], int n) {
    int l[n];
    int r[n];

    int maxi = a[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
        l[i] = maxi;
    }

    int mini = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {

        mini = min(mini, a[i]);
        r[i] = mini;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] >= l[i - 1] and a[i] <= r[i + 1])
        {
            return a[i];
        }
    }

    return -1;
}