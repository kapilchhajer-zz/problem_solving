//http://www.spoj.com/problems/TOE2/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool Win( char *str, char ch){

		if( str[0] == ch && str[0] == str[1] && str[1] == str[2])
			return true;
		
		if( str[3] == ch && str[3] == str[4] && str[4] == str[5])
			return true;
		
		if( str[6] == ch && str[6] == str[7] && str[7] == str[8])
			return true;

		if( str[0] == ch && str[0] == str[4] && str[4] == str[8])
			return true;

		if( str[2] == ch && str[2] == str[4] && str[4] == str[6])
			return true;

		if( str[0] == ch && str[0] == str[3] && str[3] == str[6])
			return true;

		if( str[1] == ch && str[1] == str[4] && str[4] == str[7])
			return true;

		if( str[2] == ch && str[2] == str[5] && str[5] == str[8])
			return true;

		return false;

}


int main(){

	char str[10];
	int xCount, oCount, temp;
	bool xCheck, oCheck, completeFlag;
	scanf("%s",str);

	while( strcmp(str, "end")){

		xCount = oCount = 0;
		completeFlag = true;

		for( int i = 0; i < 9; i++){

			if( str[i] == 'X')
				xCount++;
			else if( str[i] == 'O')
				oCount++;

		}
		temp = xCount - oCount;
		
		if( xCount + oCount < 9)
			completeFlag = false;

		if( temp == 0 || temp == 1){

			xCheck = Win( str , 'X');
			oCheck = Win( str , 'O');

			if( !completeFlag && !(xCheck || oCheck))
				printf("invalid\n");
			else if( (temp == 1 &&  !oCheck) || (temp == 0 && !xCheck) )
				printf("valid\n");	
			else
				printf("invalid\n");
		}
		else	
			printf("invalid\n");
		
		scanf("%s",str);
	}
	
}
