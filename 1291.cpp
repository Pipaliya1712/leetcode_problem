/*
1291. Sequential Digits ( Medium )

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 
Constraints:

10 <= low <= high <= 10^9
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sequentialDigits(int low, int high) {
    vector<int> a = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
    vector<int> ans;
    for(int i=0;i<36;i++){
        if(a[i]>=low && a[i]<=high) ans.push_back(a[i]);
    }
    return ans;
}

int main(){
    int low,high;
    cin>>low>>high;
    vector<int> ans;
    ans=sequentialDigits(low,high);
    for(auto a: ans){
        cout<<a<<" ";
    }
    return 0;
}