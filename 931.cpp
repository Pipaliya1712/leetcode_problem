/*
931. Minimum Falling Path Sum ( Medium )
 
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum which is 1->5->7 ans 1->4->8.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum which is -19->-40.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    if(matrix.size()==1) return matrix[0][0];
    for(int i=matrix.size()-2;i>=0;i--){
        for(int j=0;j<matrix.size();j++){
            int x=INT_MAX,y=INT_MAX,z=INT_MAX;
            y=matrix[i+1][j]+matrix[i][j];
            if(j!=0) x=matrix[i+1][j-1]+matrix[i][j];
            if(j!=matrix.size()-1) z=matrix[i+1][j+1]+matrix[i][j];
            matrix[i][j] = min(x,min(y,z));
        }
    }
    return *min_element(matrix[0].begin(),matrix[0].end());
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            matrix[i].push_back(x);
        }
    }
    cout<<minFallingPathSum(matrix)<<endl;
    return 0;
}