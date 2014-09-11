#include<iostream>
#include<cstdio>
#include<climits>
#include<cstdlib>
using namespace std;

int main()
{
	long long int N,K;
	long long int max = 	LONG_MIN;
	scanf("%lld %lld",&N,&K);
	long long int *num;
	num = ( long long int *) malloc ( sizeof( long  long int) * N );
	
	for(int i=0;i<N;i++){
		scanf("%lld",&num[i]);
		if(num[i]>max)
			max=num[i];

	}
	if(K%2==1){
			for(int i=0;i<N;i++)
				printf("%lld ",max-num[i]);
			printf("\n");
	}
	else{
		long long int max1 = LONG_MIN;
		if(K>=2){
			K=2;
			while(K--){
				for(int i=0;i<N;i++){
					num[i] = max - num[i];
					if(max1<num[i])
						max1=num[i];
				}
				max = max1;
			}
		}
		for(int i=0;i<N;i++)
			printf("%lld ",num[i]);
		printf("\n");
	}

	
	return 0;
}
