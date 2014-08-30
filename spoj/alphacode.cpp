//http://www.spoj.com/problems/ACODE/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){

	char in[5001];
	long long int count, sum;
	long int fib[5002];

	fib[0] = fib[1] = 1;

	for(int i = 2; i < 5002 ; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	scanf("%s", in);

	while( strcmp(in,"0") != 0){
		
		sum = 1;
		count = 0;

		for(int i = 0; in[i] != '\0'; i++){

			if(  in[i + 1] != '0' && ( in[i] == '1' || ( in[i] =='2' && in[i + 1] <= '6' ) ) ){
				count++;
				continue;
			}			
			
			if(count > 0){
				if(in[i + 1] != '0')
					count++;
				sum = sum * fib[count];
				count = 0;
			}
			
		}
		if( count > 0 )
			sum = sum * fib[count];
		
		printf("%lld\n" , sum);
		scanf("%s", in);

	} 
	
	return 0;
}
