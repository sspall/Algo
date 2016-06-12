#include <stdio.h>
#define SIZE 10
#define MAX(a,b) a>b?a:b

int LIS(int input[], int size) {
	int i,j;
	int arr[SIZE], max =0;

	for(i=0;i<size;i++)
		arr[i] = 1;

	for(i=1;i<size;i++) {
		for(j=0;j<i;j++) {
			if(input[j] < input[i]) {
				arr[i] =MAX(arr[i], arr[j] + 1);
			}
		}
	}

	for(i=1;i<size;i++) {
		max = MAX(max, arr[i]);
	}
	return max;
}

int main(){
	int a[] = {3,4,-1,0,6,2,3};
	printf("%d",LIS(a,sizeof(a)/sizeof(int)));
	return 0;
}
