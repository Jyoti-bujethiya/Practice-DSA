class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,hi=arr.size()-1;
        if(arr[0]>arr[1])
            return 0;
        if(arr[arr.size()-1]>arr[arr.size()-2])
            return arr.size()-1;
        
        while(low<hi){
            int mid= hi+(-hi+low)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
                return mid;
            if(arr[mid]<arr[mid-1])
                hi=mid-1;
            else
                low=mid;
        }
        return -1;
    }
};