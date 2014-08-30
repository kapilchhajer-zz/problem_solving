//https://www.hackerrank.com/challenges/is-fibo

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

long long int f[100000], length;

void fib(){

	long long int size = ((long long int)100000) * 100000 + 1, i;
	
	f[0] = 0;
	f[1]  = f[2] = 1;
		
	for(i = 3; f[i - 1] < size; i++)
		f[i] = f[i - 1] + f[i-2];

	length = i;
}

int main(){

	int testCases;
	long long int num;

	fib();
	
	scanf("%d", &testCases);

	while( testCases-- ){

		scanf("%lld", &num);
		
		if( binary_search( f , f + length , num) )
			printf("IsFibo\n");
		else
			printf("IsNotFibo\n");
		

	}

	return 0;
}
