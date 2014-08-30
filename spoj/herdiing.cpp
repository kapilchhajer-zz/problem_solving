//http://www.spoj.com/problems/HERDING/

#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

bool visited[1000][1000] = {0};
char connect[1000][1000];
int N, M;

void bfs(int i, int j){


	visited[i][j] = true;

	int posX = i, posY = j;

	

		if( posX > 0 && connect[posX][posY] == 'N' && !visited[posX - 1 ][posY]){
				visited[posX - 1][posY] = true;
				bfs(posX - 1 , posY);
		}
		else if(  posX + 1 < N && connect[posX][posY] == 'S' && !visited[posX + 1 ][posY]){
				visited[posX + 1][posY] = true;
				bfs(posX + 1 , posY);
		}
		else if( posY + 1 < M && connect[posX][posY] == 'E' && !visited[posX][posY + 1]){
				visited[posX][posY + 1] = true;
				bfs(posX , posY + 1);
		}
		else if( posY > 0 && connect[posX][posY] == 'W' && !visited[posX][posY - 1]){
				visited[posX][posY - 1] = true;
				bfs(posX , posY - 1);
		}


		if( posX + 1 < N   && connect[posX + 1][posY] == 'N' && !visited[posX + 1][posY] ){
				visited[posX + 1][posY] = true;
				bfs(posX + 1 , posY);
			
		}

		if( posX  > 0   && connect[posX - 1][posY] == 'S' && !visited[posX - 1][posY] ){
				visited[posX - 1][posY] = true;
				bfs(posX - 1 , posY);
			
		}
		
		if( posY + 1 < M   && connect[posX][posY + 1] == 'W' && !visited[posX][posY + 1] ){
				visited[posX][posY + 1] = true;
				bfs(posX , posY + 1);
			
		}
		
		if( posY > 0   && connect[posX][posY - 1] == 'E' && !visited[posX][posY - 1] ){
				visited[posX][posY -1] = true;
				bfs(posX , posY - 1);
			
		}
	
}

int main(){


	scanf("%d %d", &N, &M);
	
	
	for( int i = 0; i < N; i++)
		scanf("%s", connect[i]);

	int count = 0;
	for( int i = 0; i < N; i++){

		for( int j = 0; j < M; j++){

			if(!visited[i][j]){
				bfs(i,j);
				count++;
			}
		}
	}		
	printf("%d\n",count);
	return 0;
}

