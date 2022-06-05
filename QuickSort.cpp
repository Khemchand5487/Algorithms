#include <bits/stdc++.h>

using namespace std;

/*
    Description: Firstly, we will take any element from array called pivot element.
                 Then find the correct postiotion of that pivot element in array i.e.
                 all the element in left of the pivot element is shorter then pivot 
                 and all the element in right of the pivot element is greater the pivot element.
                 And put that pivot element at its correct postiotion
    
    Time Complexity: Best: O(nlogn), Worst: O(n*n)
    Space Complexity: O(1)
*/


int partition(int arr[], int l, int r) {
    
    int i=l, j=l;
    
    while(j<r) {
        if(arr[j]<=arr[r]){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[r]);
    return i;
}

void quick_sort(int arr[], int l , int r) {
    
    if(l<=r) {
        int pivot = partition(arr, l, r);
        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, r);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    quick_sort(arr, 0, n-1);
    
    for(int i: arr) cout<<i<<" ";

    return 0;
}
