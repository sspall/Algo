//5_DP_LongestBitonicSubsequence

#include <stdio.h>
#define SIZE 10
#define MAX(a,b) a>b?a:b

int LIS(int input[], int size) {
	int i,j;
	int arr1[SIZE], max =0,arr2[SIZE];

	for(i=0;i<size;i++) {
		arr1[i] = 1;
		arr2[i] = 1;
	}

	for(i=1;i<size;i++) {
		for(j=0;j<i;j++) {
			if(input[j] < input[i]) {
				arr1[i] =MAX(arr1[i], arr1[j] + 1);
			}
		}
	}

	for(i=size-2;i>=0;i--) {
		for(j=size-1;j>i;j--) {
			if(input[j] < input[i]) {
				arr2[i] =MAX(arr2[i], arr2[j] + 1);
			}
		}
	}

	for(i=0;i<size;i++) {
		max = MAX(max, arr1[i]+arr2[i]-1);
	}
	return max;
}

int main(){
	int a[] = {2,-1,4,3,5,-1,3,2};
	printf("%d",LIS(a,sizeof(a)/sizeof(int)));
	return 0;
}
