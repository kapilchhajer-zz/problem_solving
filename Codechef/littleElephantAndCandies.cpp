//http://www.codechef.com/problems/LECANDY

#include<cstdio>
using namespace std;

int main(){

	int testCases,N;
	long int C,sum,temp;

	scanf("%d",&testCases);

	while(testCases--){
		sum = 0;
		scanf("%d %ld",&N,&C);

		while(N--){
			scanf("%ld",&temp);
			sum = sum + temp;
		}

		if( sum <= C)
			printf("Yes\n");
		else
			printf("No\n");		
		
	}

	return 0;
}

