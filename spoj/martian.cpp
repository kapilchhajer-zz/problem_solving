//http://www.spoj.com/problems/MARTIAN/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


int main(){

	int M, N;
	scanf("%d%d",&M,&N);

	while(M != 0 && N != 0){

		char arrow[501][501];
		int upArrow[501][501], leftArrow[501][501], value[501][501] = { 0 };

		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				scanf("%d",&leftArrow[i][j]);

		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
				scanf("%d",&upArrow[i][j]);

		
		for(int i = M -1 ; i >= 0; i--){

			for(int j = N - 1; j >= 0; j--){
				
				if( upArrow[i][j] >= leftArrow[i][j]){
					
					value[i][j] =  upArrow[i][j] - leftArrow[i][j];
					arrow[i][j] = '^';
				}
				else{

					value[i][j] = leftArrow[i][j] - upArrow[i][j];
					arrow[i][j] = '<';
				}	

					
				if(arrow[i][j] == '^' && arrow[i + 1][j] == '^'){

						value[i][j] = value[i][j] + value[i + 1][j];
				}
				else if(arrow[i][j] == '<' && arrow[i][j + 1] == '<'){

						value[i][j] = value[i][j] + value[i][j + 1];
				}

				if( arrow[i][j] == '^' && arrow[i][j + 1] == '<'){
						
					if( value[i][j + 1]  <= value[i][j] ){

						value[i][j] = value[i][j] - value[i][j + 1];
					}					
					else{
						arrow[i][j] = '<';
						value[i][j] = value[i][j + 1] -value[i][j];
					}

				}
				else if(arrow[i][j] == '<' && arrow[i + 1][j] == '^'){

					if(value[i + 1][j] <  value[i][j]){
						
						value[i][j] -=  value[i + 1][j];
					}
					else{
						arrow[i][j] = '^';
						value[i][j] = value[i + 1][j] - value[i][j];
					}
				}

			}
		}		
		
		/*
		for(int i = 0; i < M; i++){

			for(int j =0; j < N; j++)
				printf("  %c  ",arrow[i][j]);
		
			printf("\n");
		}

		for(int i = 0; i < M; i++){

			for(int j =0; j < N; j++)
				printf("  %d  ",value[i][j]);
		
			printf("\n");
		}
		*/
		long long int count = 0;

		for(int i = 0; i < M; i++){

			for(int j = 0; j < N; j++){
			
				if(arrow[i][j] == '^'){
	
					count += upArrow[i][j];
					arrow[i][j + 1] = '^';					 

				}
				else {
					count += leftArrow[i][j];
					arrow[i + 1][j] = '<';

				}				
		
			}
		}

		printf("%lld\n",count);
		scanf("%d%d",&M,&N);
	}


	return 0;
}
