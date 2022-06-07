/*
Kadane's Algorithm: This algo is used to find the largest sum contiguous subarray

Time Complexity: O(N)
Space complexity: O(1)
*/

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


// It handled the case where all the elements in array are negative
long long maxSubarraySum(int arr[], int n){

    long long max_so_far = arr[0], curr_sum = arr[0];

    for(int i=1;i<n;i++) {
        curr_sum = max((long long)arr[i], arr[i]+curr_sum);
        max_so_far = max(curr_sum, max_so_far);
    }

    return max_so_far;
}
