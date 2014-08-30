//http://www.spoj.com/problems/ALIEN2

#include<cstdio>

int main(){

	int i,stations, maxHuman, min1, min2, prev1, prev2;

	scanf("%d %d", &stations, &maxHuman);

	int train1[stations], train2[stations];

	for( i = 0; i < stations; i++)
		scanf("%d", train1 + i); 

	for( i = 0; i < stations; i++)
		scanf("%d", train2 + i); 

	prev1 = min1 = 0;
	prev2 = min2 = 0;
			
	for( i = 0; i < stations; i++){

			
		if( min1 <= min2 + train2[i] )
			min1 = min1 + train1[i];
		else
			min1 = min2 + train2[i] + train1[i];


		if( min2 <= prev1 + train1[i] )
			min2 = min2 + train2[i];
		else
			min2 = prev1 + train1[i] + train2[i];

		if(min1 > maxHuman && min2 > maxHuman)
			break;
		else{
			prev1 =  min1;
			prev2 = min2;
		}

	}

	if( i < stations )
		printf("%d %d\n", i, prev1 < prev2 ? prev1 : prev2 );
	else
		printf("%d %d\n", i, min1 < min2 ? min1 : min2 );

	
	
	return 0;
}
