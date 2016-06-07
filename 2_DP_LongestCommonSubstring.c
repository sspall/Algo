/*
 * Longest Common Substring
 */

#include <stdio.h>
#define MAX_SIZE 10

int lcs(char *s1, char *s2) {
	int matrix[MAX_SIZE][MAX_SIZE];
	int i,j, string1_len = 0, string2_len = 0;
	char *temp;
	int max = 0;

	//compute the length of string s1
	temp = s1;
	while(*temp) {
		string1_len++;
		temp++;
	}

	//compute the length of string s2
	temp = s2;
	while(*temp) {
		string2_len++;
		temp++;
	}

	for(i=0;i<=string2_len;i++) {
		for(j=0;j<=string1_len;j++) {
			//initialize the first row and first column with 0
			if(i==0 || j==0) {
				matrix[i][j] = 0;
				continue;
			}

			if(s2[i-1] == s1[j-1]) {	//is string match then pick value diagonally previous element and add 1
				matrix[i][j] = matrix[i-1][j-1] + 1;
			} else { // otherwise set t 0
				matrix[i][j] = 0;
			}
		}
	}

	//just for testing
	for(i=0;i<=string2_len;i++) {
		for(j=0;j<=string1_len;j++) {
			if(max < matrix[i][j])
				max = matrix[i][j];
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	return max;
}

int main() {
	char string1[] = "bccaf";
	char string2[] = "acbcc";

	printf("%d",lcs(string1, string2));
	return 0;
}
