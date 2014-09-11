//http://www.spoj.com/problems/THEATRE/

#include<iostream>
#include<cstdio>
#include<stack>

#define MAX 100000
#define LIMIT 1000000007
using namespace std;


int main(){

	long int  Arr[MAX], N;
	unsigned long long int total = 1;
	stack<long int> stk;


	scanf("%ld", &N);

	for(int i = 0; i < N; i++)
		scanf("%ld", &Arr[i]);
		
		
	for(int j = N - 1; j >= 0; j--){

		while(!stk.empty()){
			
			if(Arr[j] < stk.top())
				break;
	
			stk.pop();
		}

		if(!stk.empty())
			total = (total * stk.top()) % LIMIT;

		stk.push(Arr[j]);	
	}

	printf("%llu\n", total);


	return 0;
}
