/******************************************************************************
Problme description: Implementaion of Insertion Sort 

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n) {
     /*
        Description: we divide the array into two halfs one is sorted and another
                    is unsorted. Then, for every element of unsorted array, we will
                    find the correct position in sorted array and place it on the same.
        
        Time Complexity: O(n^2)
        Space Complexity: O(1)
    */
    
    for(int i=1;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
            else break;
        }
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
    
    insertionSort(arr, n);
    cout<<"Array after sorting: ";
    for(int i: arr) cout<<i<<" ";
    
    return 0;
}
