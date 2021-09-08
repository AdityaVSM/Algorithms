#include<bits/stdc++.h>
using namespace std;

//NAIVE O((n-k)*k)
int maxSum1(int arr[], int n, int k){
    int res = INT_MIN;
    for(int i=0; (i+k-1)<n; i++){
        int sum = 0;
        for(int j=i; j<i+k; j++){
            sum += arr[j];
        }
        res = max(res,sum);
    }
    return res;
}

//Sliding window to find max sum of k consecutive ele O(N) 
int maxSum2(int arr[], int n, int k){
    int curr_sum = 0;
    for(int i=0; i<k; i++)
        curr_sum += arr[i];
    int res = curr_sum;
    for(int i=k; i<n; i++){
        curr_sum += (arr[i]-arr[i-k]);
        res = max(res,curr_sum);
    }
    return res;
}

//To check if given any subarray has given sum O(N) using widnow sliding window
void subArraySum(int arr[], int n, int sum){ 
	/* Initialize curr_sum as value of first element 
	and starting point as 0 */
	int curr_sum = arr[0], start = 0, i; 

	/* Add elements one by one to curr_sum and if the curr_sum exceeds the 
	sum, then remove starting element */
	for (i = 1; i <= n; i++){ 
		// If curr_sum exceeds the sum, then remove the starting elements 
		while (curr_sum > sum && start < i-1){ 
			curr_sum = curr_sum - arr[start]; 
			start++; 
		} 

		// If curr_sum becomes equal to sum, then return true 
		if (curr_sum == sum){ 
			printf ("Sum found between indexes %d and %d", start, i-1); 
		} 

		// Add this element to curr_sum 
		if (i < n) 
		    curr_sum = curr_sum + arr[i]; 
	} 

	// If we reach here, then no subarray 
	printf("No subarray found"); 
} 

int main(){
    int arr[] = {5,-10,6,90,3};
    int k = 2;
    int n = 5;
    cout << maxSum1(arr,n,k) << endl;
    cout << maxSum2(arr,n,k) << endl;
    int arr2[] = {1,4,20,3,10,5};
    n = 6;
    subArraySum(arr,n,33);
    return 0;
}