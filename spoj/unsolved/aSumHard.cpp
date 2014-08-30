//http://www.spoj.com/problems/ASUMHARD/

#include<iostream>
#include<cstdio>
#define MODE 1234567891

using namespace std;


unsigned long int power( unsigned long int i , unsigned long int K){

	int arr[200] = {0}, j = 0;
	unsigned long int P = K, result;
	
	if ( K == 0 )
		return 1;

	while( P ){

		arr[j] = P % 2;
		P  = P/2;
		j++;
	}

	j = j - 2;

	result = i;

	for( ; j >= 0 ; j-- ){

		result =  (result * result) % MODE;		

		if ( arr[j] == 1){

			result = (result * i) % MODE;

		}
	}


	return result;

}


int main(){::

	unsigned long int testCases, N, K, result, temp, i;

	
	scanf("%lu", &testCases);


	while(testCases--){

		result = temp = 0;

		scanf("%lu%lu", &N, &K);	

		for(i = 1; i <= N; i++){
			
			temp = ( temp + power(i , K) ) % MODE;
			result = (result + temp) %  MODE;
		}

		printf("%lu\n",result);
	}	 

	return 0;
}
