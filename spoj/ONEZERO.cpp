//http://www.spoj.com/problems/ONEZERO/

#include<iostream>
#include<cstdio>

using namespace std;

bool zeroOne(long long int num){

	int rem;

	while( num ){

		rem = num % 10;
		
		if( rem > 1) return false;

		num = num / 10;
	}
	
	return true;
}

int main(){

	
	int testCases, rem;
	long long int result, num;
	scanf("%d", &testCases);

	while( testCases-- ){

		scanf("%lld", &num);

		rem = num % 10;

		switch(rem){

		case 0 :
		case 1 :
				result = num;
				break;
		case 2 :
		case 4 :
		case 6 :
		case 8 :
				result = num * 5;
				break;
		case 3 :
				result = num * 7;
				break;
		
		case 5 :
				result = num * 2;
				break;
		case 7 : 
				result = num * 3;
				break;

		case 9 :
				result = num * 9;
				break;
		}

		num = num * 10;

		while( !zeroOne(result) ){

			result = result + num;

		}

		printf("%lld\n", result);
	}
	return 0;
}
