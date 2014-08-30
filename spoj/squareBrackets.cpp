//http://www.spoj.com/problems/SQRBR/

#include<cstdio>

using namespace std;

int main(){

	int testCases, temp, N, K, dp[40][40];

	scanf("%d", &testCases);

	while( testCases-- ){
	
		char position[40] = {0};
		
		scanf("%d %d", &N, &K);

		for(int i = 0; i < K; i++){
			
			scanf("%d",&temp);
			position[temp]  = '[';
		}
		
		N = N << 1;

		for(int i = 0; i <= N; i++)
			dp[1][i] = 0;

		dp[1][1] = 1;  // this dp matrix counts no of jth greater than '[' than ']'  from first ith elements and dp[1][1] = 1 is base case.

		for(int i = 2; i <= N; i++){

			for(int j = 0; j <= N; j++){

				dp[i][j] = 0;
				
				if(j != 0)
					dp[i][j] = dp[i][j] + dp[i - 1][j - 1];

				if(position[i] != '[' &&  j != N)
					dp[i][j] = dp[i][j] + dp[i - 1][j + 1];
			}

		}


		printf("%d\n",dp[N][0]);
	}

	return 0;
}
