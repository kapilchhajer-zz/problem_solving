//http://www.spoj.com/problems/YODA/

#include<cstdio>
#include<iostream>

using namespace std;


int main(){

	char str[1000000];
	int oddCount, count;
	unsigned long long int result, fact, inc;
 	
	while( gets(str) != NULL ){

		int alpha[26] = {0};
		oddCount = 0;
		result = 1;

		for( int i = 0; str[i] != '\0' ; i++){

			if( str[i] >= 'A' && str[i] <= 'Z')
				alpha[ str[i] - 'A' ]++;
			else if( str[i] >= 'a' && str[i] <= 'z')
				alpha[ str[i] - 'a']++;

		}


		for( int i = 0; i < 26; i++)
			if( alpha[i] % 2 )
				oddCount++;

		if( oddCount > 1 ){

			printf("0\n");
			continue;
		}

		inc = 1; 
		for( int i = 0; i < 26; i++ ){

			if( alpha[i] % 2)
				alpha[i] -= 1;

			count = alpha[i] / 2;
			fact = 1;

			for( ; count > 0; count--,fact++, inc++ )
				result =  result *  inc / fact ;

		}
	
		printf("%llu\n",result);
	}
	
	return 0;
}
