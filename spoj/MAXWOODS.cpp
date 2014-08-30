//http://www.spoj.com/problems/MAXWOODS/

#include<iostream>
#include<cstdio>

using namespace std;

void maxWood(){

	int M, N;

	scanf("%d %d", &M, &N);
		
	char wood[M][N];
	int  mem[M][N];

	for(int i = 0; i < M; i++)
		for( int j = 0; j < N; j++)
			scanf(" %c", &wood[i][j]);
	

	int upper, side;
	
	if( wood[0][0] == '#'){

		printf("0\n");
		return;
	}
	
	int j, tempMax, max = 0;

	for( int i = 0; i < M; i++){

		if( i % 2 == 0){

			if( i == 0){
			
				if( wood[0][0] == '0')
					mem[0][0] = 0;
				else{
					mem[0][0] = 1;
					max = 1;
				}
				j = 1;
			}
			else
				j = 0;

			for( ;j < N; j++){		
			
				if( i == 0)
					upper = -1;
				else
					upper = mem[i - 1][j];


				if( j == 0)
					side = -1;
				else 
					side = mem[i][j - 1];

					
				if( upper == -1 && side == -1)
					mem[i][j] = -1;
				else{
					 if( upper > side)
						tempMax = upper;
					 else		
						tempMax =  side;
			
					if(wood[i][j] == '#')
						mem[i][j] = -1;	
					else if( wood[i][j] == '0')
						mem[i][j] = tempMax;
					else
						mem[i][j] = tempMax + 1;
				}

				if( mem[i][j] > max)
					max = mem[i][j];
			}
		}
		else{
			for( int j = N -1; j >= 0; j--){
				
				upper = mem[i - 1][j];

				if( j == N - 1)
					side = -1;
				else 
					side = mem[i][j + 1];

					
				if( upper == -1 && side == -1)
					mem[i][j] = -1;
				else{
					 if( upper > side)
						tempMax = upper;
					 else		
						tempMax =  side;
			
					if(wood[i][j] == '#')
						mem[i][j] = -1;	
					else if( wood[i][j] == '0')
						mem[i][j] = tempMax;
					else
						mem[i][j] = tempMax + 1;
				}
	
				if( max < mem[i][j])
					max = mem[i][j];
			}


		}
	}

	printf("%d\n", max);
}



int main(){

	int testCases;

	scanf("%d", &testCases);

	while( testCases--)
		maxWood();
		

	return 0;
}
