//http://www.spoj.com/problems/FIBOSUM/

#include<iostream>
#include<cstdio>

#define MODE 1000000007 

using namespace std;

long int fib(long int N){
	
	if( N == 0)
		return 0;

	if( N <= 2)
		return 1;
	
	long long int result1 = 1, result2 = 1, result3 = 1, result4 = 0, temp1,temp2,temp3,temp4, t1,t2,t3,t4 = 0 ;
	t1 =t2 =t3 =1;	

	for( long int i = N - 2; i > 0 ;){
	
		if( i % 2  ==  1 ){
			temp1 = (( result1 * t1) % MODE + (t2 * result3 )  % MODE) % MODE;
			temp2 = ( (result2 * t1) % MODE + (t2 * result4 ) % MODE ) % MODE;
			temp3 = ( (result1 * t3) % MODE + (t4 * result3 ) % MODE ) % MODE;
			temp4 = ( (result2 * t3) % MODE + (t4 * result4 ) % MODE ) % MODE;
			t1 = temp1;
			t2 = temp2;
			t3 = temp3;
			t4 = temp4; 
		}	
			temp1 = ( (result1 * result1) % MODE + ( result2 * result3 ) % MODE ) %MODE;
			temp2 = ( (result1 * result2) % MODE + ( result2 * result4 ) % MODE ) % MODE;
			temp3 = ( (result3 * result1) % MODE + ( result4 * result3 ) % MODE ) % MODE;
			temp4 = ( (result3 * result2) % MODE + ( result4 * result4 ) % MODE ) % MODE; 
			
			result1 = temp1;
			result2 = temp2;
			result3 = temp3;
			result4 = temp4; 
			i = i /2;
		
	}	

	return t1;

}

int main(){


	long long int testCases, N, M ;

	scanf("%lld", &testCases);

	while( testCases-- ){

		scanf("%lld %lld", &N, &M);

		long long int sum1 = 0, sum2 = 0;

		N = N + 1;
		M = M + 2;

		sum1 =  fib(N) - 1;
		sum2 = fib(M) - 1;

		printf("%lld\n", (sum2  + MODE - sum1) % MODE);
		
		
	}


	return 0;
}
