//http://www.spoj.com/problems/LISA/

#include<iostream>
#include<cstdio>
#include<climits>

typedef unsigned long long llu;

using namespace std;

int main(){


	llu testCases,  l, m, dpMax[101][101], dpMin[101][101], size, valueMax, valueMin, indexRow, indexmid, indexCol;
	char str[1000], oper;
	int length;

	scanf("%llu", &testCases);


	while( testCases-- ){

		length = -1;

		scanf("%s", str);
	
		for( llu i = 0, j = 0; str[i] != '\0'; i++){

			if( i % 2 == 0){
				
				dpMax[j][j] = dpMin[j][j] = str[i] - '0';
				length = length + 2;
				j++;
			}
		}


		size = (length + 1) / 2;

		for( llu i = 2; i <= size; i++){

			l = (size - i) * i;

			for( llu j = 0; j <= l; j = j + 2){

				m = j + ( i - 1 ) * 2;
				indexCol = m / 2;
				indexRow = j / 2;
				dpMax[indexRow][indexCol] = 0;
				dpMin[indexRow][indexCol] = LLONG_MAX;
					
				for( llu k = j; k < m; k = k + 2){

					indexmid = k / 2;
					oper = str[k + 1];
					

					if( oper == '+'){

						valueMax = dpMax[indexRow][indexmid] + dpMax[indexmid + 1][indexCol];
						valueMin = dpMin[indexRow][indexmid] + dpMin[indexmid + 1][indexCol];
					}
					else{

						valueMax = dpMax[indexRow][indexmid] * dpMax[indexmid + 1][indexCol];
						valueMin = dpMin[indexRow][indexmid] * dpMin[indexmid + 1][indexCol];

					}
				
					if( valueMin < dpMin[indexRow][indexCol])
						dpMin[indexRow][indexCol] = valueMin;

					if( valueMax > dpMax[indexRow][indexCol])
						dpMax[indexRow][indexCol] = valueMax;
				}

			}

		}

		if(length == -1)
			printf("0 0\n");
		else
			printf("%llu %llu\n",dpMax[indexRow][indexCol] , dpMin[indexRow][indexCol]);

	}

	return 0;
}
