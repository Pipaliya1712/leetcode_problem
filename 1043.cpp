/*
1043. Partition Array for Maximum Sum ( Medium )

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1
 
Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/

#include<bits/stdc++.h>
using namespace std;

int solv(int i,vector<int>& arr,int k,vector<int>& dp){
    int n = arr.size();
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int len=0;
    int maxi=INT_MIN, maxAns=INT_MIN;
    for(int j=i;j<min(i+k,n);j++){
        len++;
        maxi = max(maxi,arr[j]);
        int sum = len * maxi + solv(j+1,arr,k,dp);
        maxAns = max(maxAns, sum);
    }
    return dp[i] = maxAns;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> dp (arr.size(),-1);
    return solv(0,arr,k,dp);
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>k;
    cout<<maxSumAfterPartitioning(arr,k)<<endl;
    return 0;
}