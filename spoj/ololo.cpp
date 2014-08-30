//http://www.spoj.com/problems/OLOLO/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	int N, temp, result = 0;

	scanf("%d",&N);
	
	for(int i = 0 ; i < N ; i++){
		
		scanf("%d",&temp);
		
		result = result ^temp;
	}
	
	printf("%d\n",result);

	return 0;
}
