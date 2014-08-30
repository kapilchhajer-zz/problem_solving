//http://www.spoj.com/problems/AFS/

#include<cstdio>
#define MAX 1000001

using namespace std;


long long int result[MAX] = {0};

void fun(){

	result[0] = result[1] = 0;

	for(long int i = 2; i < MAX; i = i + 1){
		
	
		for( long int j = i + i; j < MAX; j = j + i)
				result[j] +=  i;
		
		result[i] = result[i - 1] + result[i] + 1;
	}

} 

int main(){

	fun();

	int testCases;
	long int N;

	scanf("%d",&testCases);

	while(testCases--){

		scanf("%ld",&N);
		printf("%lld\n",result[N]);
	}
	return 0;
}
