/******************************************************************************
Problme description: You are given an 2-D array of integers and you need to find 
                    index of peek element of that array.
                    A peak is define as a hill i.e. for (i, j) element in the array 
                    if arr[i][j]>=arr[i-1][j], arr[i+1][j], arr[i][j-1] and arr[i][j+1] then 
                    the element at (i, j) is called as a peek element of that array.

Input:  [[10, 8, 10, 10],
        [14, 13, 12, 11],
        [15, 9, 11, 21],
        [16, 17, 19, 20]]

Output: 21
Note: There can be more than one peek elements are present in 2-d array.
    You need to print any one of them.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int findPeek(vector<vector<int>> arr, int n, int m) {
    /*
        Description: This algorithm uses a greedy technique to find the peek element.
                    In this algorithm, we move towards the element which is greater than
                    the current element util we find the peek element. This algorithm is 
                    called Greedy Ascent Algorithm.
        
        Time Complexity: O(nm) and O(n^2) if n==m
        Space Complexity: O(1)
    */
    
    
    //if there is only on element in the array then it will peek itself
    if(n==1 && m==1) return arr[0][0];
    
    int i=0, j=0;
    while(true) {
        if(j<m-1 && arr[i][j]<arr[i][j+1]) j++;
        else if(i<n-1 && arr[i][j]<arr[i+1][j]) i++;
        else if(j>0 && arr[i][j]<arr[i][j-1]) j--;
        else if(i>0 && arr[i][j]<arr[i-1][j]) i--;
        else return arr[i][j];
    }
}


int findPeek_efficient(vector<vector<int>> arr, int n, int m, int col_start, int col_end) {
    /*
        Description: This algorithm is more efficient then the above one. This algorithm
                    uses the divide and conquer technique or binary seacrh.
                    Steps:
                    m = number of columns
                    n = number of rows
                    - Pick middle column j = m/2
                    - Find global maximum on column j at (i, j)
                    - if arr[i][j-1]>arr[i][j] then move towards left columns
                    - if arr[i][j+1]>arr[i][j] then move towards right columns
                    - if neither condition is hold then (i, j) is peek element
                    - When you have a single column, find global maximum and you‘re done
        
        Time Complexity: O(n*logm)
        Space Complexity: O(1)
    */
    
    //Base case
    if(col_start>=col_end) {
        //if there is only one column in array then just find global maximum
        int global_max=INT_MIN;
        for(int i=0;i<n;i++){
            global_max = max(arr[i][col_start], global_max);
        }
        return global_max;
    }
    
    int mid = col_start + (col_end - col_start)/2;
    
    //findind index of global maximum
    int global_max_i=0;
    for(int i=0;i<n;i++){
        if(arr[i][mid]>arr[global_max_i][mid]) {
            global_max_i = i;
        }
    }
    
    
    if(mid>0 && arr[global_max_i][mid]<arr[global_max_i][mid-1]) {
        return findPeek_efficient(arr, n, m, col_start, mid-1); // moving towards left
    }
    else if(mid<m-1 && arr[global_max_i][mid]<arr[global_max_i][mid+1]) {
        return findPeek_efficient(arr, n, m, mid+1, col_end); // moving towards right
    }
    else {
        return arr[global_max_i][mid]; //peek element
    }
    
}

int main()
{
    //INPUT
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    //END
    
    cout<<"Peek element is at index: "<<findPeek(arr, n, m)<<endl;
    cout<<"Peek element is at index: "<<findPeek_efficient(arr, n, m, 0, m-1)<<endl;

    return 0;
}
