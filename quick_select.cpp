// kth smallest element using quick select

/*
Time complexity:
Best: O(N)
Worst: O(N*N)
*/

int partition(int arr[], int l, int r) {
        
    int i=l, j=l;
    while(j<r) {
        if(arr[j]<=arr[r]) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[r]);
    return i;
}

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {

    int pos = partition(arr, l, r);
    if(pos+1==k) return arr[pos];
    else if(pos+1<k) return kthSmallest(arr, pos+1, r, k);
    else return kthSmallest(arr, l, pos-1, k);

}
