/*

Code
76. Minimum Window Substring ( Hard )

Given two strings s and t of lengths m and n respectively, return the minimum window 
substringof s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.size();
    if(t.size() > n) return "";
    unordered_map <char,int> mp;
    for(auto a : t) mp[a]++;
    int rc = t.size(), i=0,j=0,mws = INT_MAX,start_i = 0;
    while(j<n){
        char ch = s[j];
        if(mp[ch] > 0) rc--;
        mp[ch]--;
        while(rc == 0){
            int cws = j-i+1;
            if(mws > cws){
                mws = cws;
                start_i=i;
            }
            mp[s[i]]++;
            if(mp[s[i]]>0) rc++;
            i++;
        }
        j++;
    }
    return mws == INT_MAX ? "" : s.substr(start_i,mws);
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<minWindow(s,t)<<endl;
    return 0;
}