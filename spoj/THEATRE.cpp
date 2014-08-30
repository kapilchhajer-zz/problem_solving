//http://www.spoj.com/problems/THEATRE/

#include<iostream>
#include<cstdio>
#include<stack>

#define MODE 1000000007

using namespace std;

int main(){

	unsigned long long int  result = 1;
	long int  N,temp;
	stack<long int> stk;

	scanf("%ld", &N);


	for( int i = 0; i < N; i++){
	
		scanf("%ld", &temp);

		while( !stk.empty() && stk.top() < temp){
			result = (result * temp) % MODE;
			stk.pop();
		}

		stk.push(temp);

	}

	printf("%llu\n", result);





}
