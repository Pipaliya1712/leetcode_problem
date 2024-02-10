/*
647. Palindromic Substrings ( Medium )

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    int n=s.size();
    int ans=n;
    vector<vector<bool>> dp(n,vector<bool>(n));
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]) {
            dp[i][i+1]=1;
            ans++;
        }
    }
    for(int i=2;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[j-i]==s[j] && dp[j-i+1][j-1]){ 
                ans++;
                dp[j-i][j]=1;
            }
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<countSubstrings(s)<<endl;
    return 0;
}