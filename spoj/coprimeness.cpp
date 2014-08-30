//http://www.spoj.com/problems/IITKWPCB/

#include<cstdio>

using namespace std;

bool gcd(long long int A , long long int B){

	if(B == 0 )
		return A == 1;

	return gcd( B , A % B );
}

int main(){

	long long int testCases,N,temp;

	scanf("%lld",&testCases);

	while( testCases-- ){

		scanf("%lld",&N);
		
		temp = N / 2;

		for( long long int i = temp; i >= 1 ; i--){

			if( gcd( N , i) ){
				printf("%lld\n", i );
				break;
			}

		}
	}

	return 0;
}
