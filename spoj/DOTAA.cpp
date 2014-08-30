//http://www.spoj.com/SPOJ/problems/DOTAA/


#include<iostream>
#include<cstdio>

using namespace std;


int main(){

	register int testCases, N, M, D, num, count;

	scanf("%d", &testCases);

	while(testCases--){

		scanf("%d %d %d", &N, &M, &D);
		count = 0;

		while(N--){
			
			scanf("%d", &num);
			num--;
			count = count + num / D;
		}

		if(count >= M)
			printf("YES\n");
		else
			printf("NO\n");


	}

	return 0;
}
