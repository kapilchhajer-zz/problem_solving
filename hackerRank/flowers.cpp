//https://www.hackerrank.com/challenges/flowers

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


int main(){

   int N, K;

   scanf("%d %d", &N, &K);

   int C[N];
   
	for(int i = 0; i < N; i++)
      		scanf("%d", &C[i]);
   
   sort( C , C + N);
   long long int result = 0, round = 1;
   

   for( int i = N - 1, j = 1; i >= 0; i--, j++){

	result = result + C[i] * round;
	
	if( j % K == 0)
		round++;
   }
   
   cout << result << "\n";
   
   return 0;
}
//
