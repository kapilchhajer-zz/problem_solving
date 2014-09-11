#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
#define gc() getchar_unlocked();

long int read_int() {
    register char c = gc();
    while(c < '0' || c > '9') c = gc();
    long int ret = 0;
    while(c >= '0' && c <= '9') {
    ret = 10 * ret + c - 48;
    c = gc();
    }
	return  ret;
}
int main()
{
	long int pascal[41][41];
	pascal[0][0]=1;
	
	for(int i = 1; i < 41; i++){
		pascal[i][0] = 1;

		for(int j = 1; j < i ; j++)
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];

		pascal[i][i] = 1;
	}

	long int N,M;
	N = read_int();
	M = read_int();
	
	return 0;
}
	
