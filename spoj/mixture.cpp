//http://www.spoj.com/problems/MIXTURES/

#include<cstdio>
#include<climits>

using namespace std;

int main(){

	long int N, Arr[101], M[101][101], S[101][101], value;


	while(scanf("%ld",&N)!=EOF){

		for(int i = 1; i <= N; i++)
			scanf("%ld", Arr + i);

		for(int i = 1; i <= N; i++){

			value = 0;

			for(int j = 1; j <= N; j++){

				if(i == j){
				
					M[i][j] = 0;
					value = Arr[j];
				}
				else if(i < j){
			
					value = (value + Arr[j]) % 100;
				}

				S[i][j] = value;
			}
		}

		long int p,q,temp;

		for(int i = 2; i <= N; i++){
	
		
			for(int j = 1; j <= N - i + 1; j++){
		
					p = j + i - 1;
					q = LONG_MAX;
				
					for(int k = j; k < p; k++){
				
						temp = M[j][k] + M[k + 1][p] + S[j][k] * S[k+1][p];
						if( temp < q){
							q = temp;
						}	

					} 
				
					M[j][p] = q;
			}
		}
	
		/*
		for(int i = 1; i <= N; i++){


			for(int j = 1; j <= N; j++){

				printf(" %ld  ",M[i][j]);
			}

			printf("\n");
		}
	
		*/
		printf("%ld\n",M[1][N]);
	}
	return 0;
}
