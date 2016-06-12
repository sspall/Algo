#include<stdio.h>
#define SIZE 10
#define MAX(a,b) a>b?a:b

int cutting_rod(int price[], int size, int len) {
	int i,j;
	int a[SIZE][SIZE];

	for(i=0;i<=size;i++) {
		for(j=0;j<=len;j++) {
			a[i][j] = 0;
		}
	}

	for(i=1;i<=size;i++) {
		for(j=1;j<=len;j++) {
			if(j<i) {
				a[i][j] = a[i-1][j];
			} else {
				a[i][j] = MAX(a[i-1][j], a[i][j-i]+price[i-1]);
			}
		}
	}

	return a[i-1][j-1];
}

int main() {
	int a[] = {2,5,7,8};

	printf("%d",cutting_rod(a,sizeof(a)/sizeof(int),5));
	return 0;
}
