//9_DP_StaircaseProblem
#include<stdio.h>
#define SIZE 50

int SP(int a[], int n) {
	if(n <= 1)
		return n;
	if(a[n] > 0)
		return a[n];

	a[n] = SP(a,n-1) + SP(a,n-2);
	return a[n];
}

// Returns number of ways to reach s'th stair
int countWays(int a[], int s)
{
    return SP(a, s + 1);
}

int main() {
	int temp_sol[SIZE];
	int i;

	for(i=0;i<SIZE;i++) {
		temp_sol[i] = 0;
	}

	printf("%d",countWays(temp_sol, 5));
	return 0;
}
