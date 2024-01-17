/*
1207. Unique Number of Occurrences ( Easy )

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    vector<int> v;
    sort(arr.begin(),arr.end());
    int temp=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]==arr[i]) temp++;
        else{
            v.push_back(temp);
            temp=1;
        }
    }
    v.push_back(temp);
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]) return false;
    }
    return true;
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<uniqueOccurrences(v)<<endl;
    return 0;
}