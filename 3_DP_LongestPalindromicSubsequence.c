/*
 * Longest Palindromic Subsequence
 */

#include <stdio.h>
#define SIZE 10
#define MAX(a,b) a>b?a:b

int lps(char *s) {
	int i,j, len_s =0, x, y;
	char *temp;
	int matrix[SIZE][SIZE];
	temp = s;

	while(*temp) {
		len_s++;
		temp++;
	}

	for(i=0;i<len_s;i++)
		for(j=0;j<len_s;j++)
			matrix[i][j] = 0;

	for(i=0;i<len_s;i++)
		matrix[i][i] = 1;

	for(i=2;i<=len_s;i++) {
		for(j=0;j<(len_s-i+1);j++) {
			x=j;
			y=i+j-1;

			if(s[x] == s[y]) {
				matrix[x][y] = matrix[x+1][y-1] + 2;
			} else {
				matrix[x][y] = MAX(matrix[x][y-1], matrix[x+1][y]);
			}

		}
	}
	//just for testing
	for(i=0;i<len_s;i++) {
		for(j=0;j<len_s;j++) {
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	return matrix[0][len_s-1];
}

int main() {
	char string2[] = "agbdba";

	printf("%d",lps(string2));
	return 0;
}
