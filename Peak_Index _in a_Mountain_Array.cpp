//Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int l=0, r=arr.size()-1;
       int n=arr.size();
       while(l<=r)
       {
           int mid=(r+l)/2;
           if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))
            return mid;
            else if(mid>0 && arr[mid-1]>arr[mid])
                r=mid-1;
            else
                l=mid+1;
       }
       return -1; 
    }
};
