//http://www.spoj.com/problems/BOI7SEQ/

#include<iostream>
#include<cstdio>

typedef long long ll;

using namespace std;

int main(){

	ll num;

	scanf("%lld", &num);
	
	register ll curr, prev, result = 0;

	scanf("%lld", &prev);
	num--;

	for( register ll i = 0; i < num; i++){

		scanf("%lld", &curr);
		
		if( prev > curr)
			result = result + prev;
		else
			result  = result + curr;

		prev = curr;
	}			

	printf("%lld\n",result);
	
	return 0;
}
