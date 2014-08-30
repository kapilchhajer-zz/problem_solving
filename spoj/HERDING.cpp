//http://www.spoj.com/problems/HERDING/

#include<iostream>
#include<cstdio>
using namespace std;

char connection[1000][1000];
int visited[1000][1000] = {0};
int N,M;

int flooding( int i , int j, int count){

	if( i >= 0 && i < N && j >= 0 && j < M){

		if( visited[i][j] != 0 && visited[i][j] <= count)
			return visited[i][j];
 
		int temp;

		visited[i][j] = count;

		switch( connection[i][j] ){

			case 'E' :	
					temp = flooding( i, j + 1 , count);
					break;
			case 'W' :

					temp = flooding( i, j - 1 , count);
					break;

			case 'N' :

					temp = flooding( i - 1, j , count);
					break;

			case 'S' :
			
					temp = flooding( i + 1, j , count);
					break;
		}

		if ( temp  < count)
			visited[i][j] = temp;

		return visited[i][j];
	}

	return count;
}

int main(){

	int count = 0, max = 0;
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++)
		scanf("%s", connection[i]);


	for( int i = 0; i < N; i++){

		for( int j = 0; j < M; j++){

			if( visited[i][j] == 0){
				count++;
				max = flooding( i , j, count);
			
				if( max < count)
					count--;			
			}
		}		
	}	

	printf("%d\n", count);	
	return 0;
}
