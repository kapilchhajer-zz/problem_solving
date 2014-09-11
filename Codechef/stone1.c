#include <stdio.h>
#include <stdlib.h>

long long N, K;
long long *A;

long long getMax() {
	long long max = A[0], i;
	for(i = 0; i < N; i++) {
		if(A[i] > max)
			max = A[i];
	}
	
	return max;	
}

int main() {

	scanf("%lld %lld", &N, &K);
	A = (long long *) malloc(sizeof(long long) * N);
	
	long long max, i;
	for(i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		if(i == 0)
			max = A[i];
		else if(A[i] > max)
			max = A[i];
	}
	
	if(K > 0) {
		for(i = 0; i < N; i++)
			A[i] = max - A[i];

		if(K > 1)
			max = getMax();

		if(K % 2 == 0) {
			for(i = 0; i < N; i++)
				A[i] = max - A[i];
		}
	}

	for(i = 0; i < N; i++)
		printf("%lld ", A[i]);
	
	printf("\n");
	return 0;
}
