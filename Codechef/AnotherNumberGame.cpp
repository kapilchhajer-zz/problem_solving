#include<iostream>
#include<cstdio>
#define gc() getchar_unlocked();
using namespace std;

long int read_num(){
	char c = gc();
	while( c < '0' && c > '9') c = gc();
	
	long int ret = 0;
	while( c >= '0' && c <= '9'){
		ret = ret * 10 + c - 48;
		c = gc();
	}
	return ret;
}

int main(){

	long int testCases,num;
	testCases = read_num();
	
	while(testCases--){
		num = read_num();
		
		num%2 ? printf("BOB\n") : printf("ALICE\n");
	}

	return 0;
}
