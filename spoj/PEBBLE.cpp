//http://www.spoj.com/SPOJ/problems/PEBBLE/

#include<cstdio>

int main(){

	char str[1000000], curr, prev, temp ;
	int num = 0;

	while( scanf("%s", str) != EOF){

		register int count = 0;
		num++;

		curr = '1';
		prev = '0';

		for( int i = 0; str[i] != '\0'; i++){

			if( curr == str[i]){
				
				count++;
				temp = curr;
				curr = prev;
				prev = temp;
			}
					
		}

		printf("Game #%d: %d\n", num , count);
	}

	return 0;
}
