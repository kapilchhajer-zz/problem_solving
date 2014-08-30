//http://www.spoj.com/problems/ABCPATH/

#include<iostream>
#include<cstdio>
#include<string>
#include<queue>

using namespace std;

int main(){

	int H, W,testCase = 0;

	scanf("%d%d", &H, &W);
	
	while( H != 0 && W != 0){

		char in[H][W];
		int visited[51][51] = {0}, cordinate[100000],c = 0, q = 0, max = 0, positionX, positionY, p = 0, loc; 
		char ch, queue[100000];

	
		for(int i = 0; i < H ; i++){

			for( int j = 0; j < W; j++){

				scanf(" %c",&in[i][j]);

				if(in[i][j] == 'A' ){
				
					cordinate[c++] = i;
					cordinate[c++] = j;
					queue[q++] = 'A';
					visited[i][j] = 1;
				}

			}

		}	
	

		while( p < q ){
	
			loc = 2 * p;
			positionX = cordinate[loc];
			positionY = cordinate[loc + 1];			

			ch = queue[p];
			p++;

			for( int i = positionX  - 1 ; i <= positionX + 1 ; i++){			

				if( i < 0 ||  i >= H)
					continue;
		
				for(int j = positionY - 1; j <= positionY + 1 ; j++){

					if( j < 0  ||  j >= W )
						continue;

					if( visited[i][j] == 0 && ch + 1 == in[i][j]){
				
						cordinate[c++] = i;
						cordinate[c++] = j;
						queue[q++] = in[i][j];
						visited[i][j] = 1;
						
					}
				
				}

			}	

			if( ch > max)
				max = ch;		
			
		}

		if(max != 0)
			printf("Case %d: %d\n", ++testCase, max - 64 );		
		else
			printf("Case %d: %d\n", ++testCase, max);		

		scanf("%d%d", &H, &W);
	}
	return 0;
}
