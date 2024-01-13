/*
1347. Minimum Number of Steps to Make Two Strings Anagram ( Medium )

You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
Return the minimum number of steps to make t an anagram of s.
An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

Example 1:
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

Example 3:
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
 
Constraints:

1 <= s.length <= 5 * 104
s.length == t.length
s and t consist of lowercase English letters only.
*/

#include<bits/stdc++.h>
using namespace std;

int minSteps(string s, string t) {
    int ans=0;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    vector<int> sv(27,0);
    vector<int> tv(27,0);
    for(int i=0;i<s.size();i++){
        sv[int(s[i])-97]++;
        tv[int(t[i])-97]++;
    }
    for(int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1] && sv[int(s[i])-97]>tv[int(s[i])-97]){
            ans+=sv[int(s[i])-97]-tv[int(s[i])-97];
        }
    }
    if(sv[int(s[s.size()-1])-97]>tv[int(s[s.size()-1])-97])
    ans+=sv[int(s[s.size()-1])-97]-tv[int(s[s.size()-1])-97];
    return ans;
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<< minSteps(s,t) <<endl; 
    return 0;
}