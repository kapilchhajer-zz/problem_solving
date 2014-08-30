//http://www.spoj.com/problems/GAMES/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int gcd(int A, int B){

	if(B == 0)
		return A;
	
	return gcd(B , A % B);
}
int main(){

	int testCases;	

	scanf("%d", &testCases);

	while( testCases-- ){

		char num[30];
		int  frac = 1, number = 0;
		bool fractionFlag = false;
		
		scanf( "%s", num );

		int len = strlen ( num ) ;

		for(int i = 0  ; i < len ; i++){

			if(num[i] == '.'){
				fractionFlag = true;
				continue;
			}

			number = number * 10 + num[i] - '0';
		
			if(fractionFlag)
				frac = frac * 10;
		}

				

		printf("%d\n" , frac / gcd(frac , number)); 
	}


	return 0;		
}
