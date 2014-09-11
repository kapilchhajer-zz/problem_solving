#include<iostream>
#include<cstdio>
using namespace std;

int main(){

	int testCases;
	long int num;

	scanf("%d",&testCases);

	while(testCases--){
		scanf("%ld",&num);
		num%2 == 0 ? printf("%ld\n",num) : printf("%ld\n",num-1);
	}
		
	return 0;
}

