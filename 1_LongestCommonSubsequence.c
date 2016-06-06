#include <stdio.h>
#define MAX_SIZE 10
#define MAX(a,b) a>b?a:b

int lcs(char s1[], char s2[], ) {
	int matrix[MAX_SIZE][MAX_SIZE];
	int i,j;

	for(i=1;i<=string2_len;i++) {
		for(j=1;j<=string1_len;j++) {
			if(string2[i-1] == string1[j-1]) {
				matrix[i][j] = matrix[i-1][j-1] + 1;
			} else {
				matrix[i][j] = MAX(matrix[i-1][j], matrix[i][j-1]);
			}
		}
	}
}

void main() {
	char string1[] = "abcdaf";
	char string2[] = "acbcf";

	int i,j,string1_len,string2_len;

	string1_len = 6;
	string2_len = 5;



}
