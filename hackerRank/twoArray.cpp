//https://www.hackerrank.com/challenges/two-arrays

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){

	long long int testCases, N, K;

	scanf("%lld", &testCases);

	while( testCases-- ){

		scanf("%lld %lld", &N, &K);

		long long int A[N],B[N];

		for(int i = 0; i < N; i++){

			scanf("%lld", A + i);
			A[i] = K - A[i];
		}
		 
		for(long long int i = 0; i < N; i++)
			scanf("%lld", B + i);

		sort(B, B + N);
		sort(A, A + N);

		bool lessFlag = false;

		for(long long int i = 0; i < N; i++){

			if( A[i] > B[i]){
			
				lessFlag = true;
				break;
			}
		}

		if(lessFlag)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
