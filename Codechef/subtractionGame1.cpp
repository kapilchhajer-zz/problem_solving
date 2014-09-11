//http://www.codechef.com/problems/AMSGAME1

#include<cstdio>
using namespace std;

long int gcd(long int A, long int B){

	if(B == 0) 
		return A;

	return gcd(B, A % B);

}
int main(){

	int testCases,N;
	long int num1,num2;

	scanf("%d",&testCases);

	while(testCases--){

		scanf("%d",&N);
		num2 = 0;

		for(int i = 0; i < N; i++){
			scanf("%ld",&num1);

			if( num2 != 1){
				num2 = gcd(num1 , num2);
			}
		}
		
		printf("%ld\n",num2);
	}

	return 0;
}
