//http://www.spoj.com/problems/TWOSQRS/

#include<iostream>
#include<cstdio>

using namespace std;


int main(){

	int testCases;

	scanf("%d", &testCases);

	long long int num;
	bool flag;

	while( testCases-- ){

		flag = true;
		scanf("%lld", &num);

		for(long long int i = 2; i * i <= num; i++){
	
			int count = 0;

			while( num % i == 0){
				count++;
				num = num / i;
			}


			if( ( i + 4 ) % 4 == 3 && count % 2 != 0 ){
				flag = false;
				break;
			}
		}
	
		if( ( num + 4 ) % 4 == 3 )
			flag = false;

		if( flag )
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}
