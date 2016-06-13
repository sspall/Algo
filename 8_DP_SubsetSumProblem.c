//8_DP_SubsetSumProblem
#include<stdio.h>
#define SIZE 12

int SSP(int arr[], int arr_len, int sum) {
	int i,j;
	int matrix[SIZE][SIZE];

	for(i=0;i<arr_len;i++) {
		for(j=0;j<sum;j++) {
			matrix[i][j] = 0;
		}
	}

	for(j=1;j<=arr_len;j++) {
		matrix[j][0] = 1;
	}

	for(j=1;j<=arr_len;j++) {
		if(arr[0]==j) {
			matrix[1][j] = 1;
		} else {
			matrix[1][j] = 0;
		}
	}

	for(i=2;i<=arr_len;i++) {
		for(j=1;j<=sum;j++) {
			if(j<arr[i-1]) {
				matrix[i][j] = matrix[i-1][j];
			} else {
				if(matrix[i-1][j] == 1) {
					matrix[i][j] = matrix[i-1][j];
				} else {
					matrix[i][j] = matrix[i-1][j-arr[i-1]];
				}
			}
		}
	}

	return matrix[i-1][j-1];
}

int main() {
	int a[] = {2,3,7,8,10};
	printf("%d",SSP(a,sizeof(a)/sizeof(int),11));
	return 0;
}
