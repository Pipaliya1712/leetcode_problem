/*
907. Sum of Subarray Minimums ( Medium )

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

#include<bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(st.empty()) left[i]=-1;
        else{
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) left[i]=-1;
            else left[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        if(st.empty()) right[i]=n;
        else{
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) right[i]=n;
            else right[i]=st.top();
        }
        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        long long l = i - left[i];
        long long r = right[i] -i;
        long long total = (arr[i]*(l*r));
        ans= (ans + total) % 1000000007;
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<sumSubarrayMins(arr)<<endl;
    return 0;
}