//http://www.spoj.com/problems/CANDY3/

#include<cstdio>

using namespace std;

int main(){

	unsigned long long int testCases,N, total, avg;

	scanf("%llu",&testCases);

	while(testCases--){
		
		scanf("%llu",&N);

		total =  0;
		unsigned long long int Arr[N];

		for(int i = 0; i < N; i++){
			scanf("%llu", Arr + i);
			total = (total + Arr[i] ) % N ;
		}


		if( total % N ){
			printf("NO\n");
			continue;
		}

		printf("YES\n");
		
		
	}
	return 0;
}
