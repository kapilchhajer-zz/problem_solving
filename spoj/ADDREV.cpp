//http://www.spoj.com/problems/ADDREV/

#include<cstdio>

using namespace std;

int main(){

	unsigned long long int A, B,reverseA, reverseB, sum, reverseSum ;
	int testCases;

	scanf("%d", &testCases);

	while( testCases-- ){

		reverseA = reverseB = reverseSum = 0;

		scanf("%llu %llu", &A, &B);

		while( A ){

			reverseA = reverseA * 10 + ( A % 10);
			A = A / 10; 
		}		

		while( B ){

			reverseB= reverseB * 10 + ( B % 10);
			B = B / 10; 
		}		

		sum =  reverseA + reverseB;

		while( sum ){

			reverseSum = reverseSum * 10 + (sum % 10);
			sum = sum / 10;
		}

		printf("%llu\n",reverseSum);
	}

	return 0;
}
