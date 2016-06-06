/*
 * Longest common subsequence
 */

#include <stdio.h>
#define MAX_SIZE 10
#define MAX(a,b) a>b?a:b

int lcs(char *s1, char *s2) {
	int matrix[MAX_SIZE][MAX_SIZE];
	int i,j, string1_len = 0, string2_len = 0;
	char *temp;

	temp = s1;
	while(*temp) {
		string1_len++;
		temp++;
	}

	temp = s2;
	while(*temp) {
		string2_len++;
		temp++;
	}

	for(i=1;i<=string2_len;i++) {
		for(j=1;j<=string1_len;j++) {
			if(s2[i-1] == s1[j-1]) {
				matrix[i][j] = matrix[i-1][j-1] + 1;
			} else {
				matrix[i][j] = MAX(matrix[i-1][j], matrix[i][j-1]);
			}
		}
	}
	return matrix[i][j];
}

void main() {
	char string1[] = "abcdaf";
	char string2[] = "acbcf";

	lcs(string1, string2);
}
