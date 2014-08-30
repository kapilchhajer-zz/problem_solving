//http://www.spoj.com/problems/AMZRCK/

#include<cstdio>

int main(){

	long int fib[45], testCases, in;

	fib[0] = 1;
	fib[1] = 2;

	for( int i = 2; i < 45; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	scanf("%ld", &testCases);

	while( testCases--){

		scanf("%ld", &in);
		printf("%ld\n", fib[in]);
	}

	return 0;

}
