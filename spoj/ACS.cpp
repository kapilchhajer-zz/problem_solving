//http://www.spoj.com/problems/ACS/

#include<cstdio>

#define COLUMN 5678


int main(){

	int row[1235], col[5679], x, y, rValue, cValue;
	long int temp;
	char mode;

	for( int i = 0; i < 1236; i++)
		row[i] = i;

	for( int i = 0; i < 5679; i++)
		col[i] = i;


	while(scanf("%c", &mode) != EOF){

		if( mode == 'W'){

			scanf("%ld", &temp);
			
			x = (temp - 1) / COLUMN + 1;
			y = (temp - 1) % COLUMN + 1;

			rValue = x;
			while( row[rValue] != x)
				rValue = row[rValue];
						
			cValue = y;
			while( col[cValue] != y)
				cValue = col[cValue];

			printf("%d %d\n", rValue, cValue);
		}
		else{
			scanf("%d %d", &x, &y);

			switch(mode){

				case 'R' :	
						temp = row[x];
						row[x] = row[y];
						row[y]= temp;
						break;
				case 'C' :
						temp = col[x];
						col[x] = col[y];
						col[y] = temp;
						break;
				case 'Q' :
						printf("%ld\n", ((long int)row[x] - 1) *  COLUMN + col[y]);
			}
		}
	}
	

	return 0;
}
