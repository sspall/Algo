//7_DP_EggDropping
#include<stdio.h>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define SIZE 10

int egg_droping(int building, int eggs) {
	int i,j,k, temp;
	int matrix[SIZE][SIZE];
	int B[SIZE], min=9999;

	for(i=0;i<=eggs;i++) {
		for(j=0;j<=building;j++) {
			matrix[i][j] = 0;
		}
	}

	for(i=1;i<=eggs;i++) {
		for(j=1;j<=building;j++) {
			if(i==1) {
				matrix[i][j] = j;
			} else if(j<i) {
				matrix[i][j] = matrix[i-1][j];
			} else {
				for(k=1;k<=j;k++) {
					temp = MAX(matrix[i-1][k-1],matrix[i][j-k]);
					B[k] = 1 + temp;
					if(min > B[k]) {
						min = B[k];
					}
				}
				matrix[i][j] = min;
				min = 9999;
			}
		}
	}
	return matrix[i-1][j-1];
}

int main() {
	printf("%d",egg_droping(6,2));
	return 0;
}
