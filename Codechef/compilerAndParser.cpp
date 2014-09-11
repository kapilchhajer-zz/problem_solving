#include<iostream>
#include<cstdio>
#include<cstring>
#define gc()  getchar_unlocked();

using namespace std;

long int read_int(){

	register char c = gc();
	while( c < '0' && c > '9') c=gc();
	long int ret=0;

	while( c >= '0' && c <= '9'){
		ret = ret * 10 + c - 48; 
		c = gc();
	}
 	
	return ret;
}
	char input[10000001];

int main(){

	long int testCases,len,max,i;
	testCases = read_int();
	
	while(testCases--){

		len = 0;
		max = 0;
		i = 0;
		scanf("%s",input);
		
		while(input[i] != '\0'){
	
			if(input[i] == '<')
				len++;
			else
				len--;
			
			
			if(len < 0)
				break;
			else if(len == 0)			
				max = i + 1;

			i++;
		}
		
		
		printf("%ld\n",max);
	}

	return 0;
}
