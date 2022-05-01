/******************************************************************************
Problme description: You are given an 1-D array of integers and you need to find 
                    index of peek element of that array.
                    A peak is define as a hill i.e. for ith element in the array 
                    if arr[i]>=arr[i-1] and arr[i]>=arr[i+1] then ith element is called as
                    a peek element of that array.

Input: [1, 2, 3, 4, 3, 2, 1]
Output: 3

Input: [6, 7, 4, 3, 2, 1, 4, 5]
Output: 1
Note: In the above example there are two peek elements one is at index 1 and another is at 7.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int findPeek(int arr[], int n) {
    /*
        Description: This is a straight forward algo where you need to traverse
                     the array from left and check for the peek element.
        
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    
    
    //if there is only on element in the array then it will peek itself
    if(n==1) return 0;
    
    for(int i=0; i<n; i++) {
        if(i>0 && i<n-1 && arr[i]>=arr[i+1] and arr[i]>=arr[i-1]) return i; 
        
        //handle the corner cases
        else if(i==0 && i<n-1 && arr[i]>=arr[i+1]) return i; //if first element of the array is peek element
        else if(i==n-1 && i>0 && arr[i]>=arr[i-1]) return i; //if last element of the array is peek element
    }
}


int findPeek_efficient(int arr[], int start, int end) {
    /*
        Description: This algorithm is more efficient then the above one. This algorithm
                    uses the divide and conquer technique or binary seacrh.
        
        Time Complexity: O(logn)
        Space Complexity: O(1)
    */
    
    if(start>=end) return start; //base condition
    
    int mid = start + (end-start)/2; // findind middle element index of the array
    
    if(arr[mid]<arr[mid+1]) {
        return findPeek_efficient(arr, mid+1, end); //looking of peek element in right half of array i.e 0....mid+1
    }
    else if(arr[mid]<arr[mid-1]) {
        return findPeek_efficient(arr, start, mid-1); //looking of peek element in left half of array i.e mid-1....n-1
    }
    else {
        return mid; // peek element index
    }
    
}

int main()
{
    //INPUT
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    //END
    
    cout<<"Peek element is at index: "<<findPeek(arr, n)<<endl;
    cout<<"Peek element is at index: "<<findPeek_efficient(arr, 0, n-1)<<endl;

    return 0;
}
