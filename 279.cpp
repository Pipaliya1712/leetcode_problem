/*
279. Perfect Squares ( Medium )

Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 
Constraints:

1 <= n <= 104
*/

#include<bits/stdc++.h>
using namespace std;


int numSquares(int n) {
    vector<int> t(n+1,100000);
    t[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<= i;j++){
            t[i]= min(t[i],1+t[i- j*j]);
        }
    }
    return t[n];
}

int main(){
    int n;
    cin>>n;
    cout<<numSquares(n)<<endl;
    return 0;
}