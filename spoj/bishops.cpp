//http://www.spoj.com/problems/BISHOPS/

#include<cstdio>
#include<cstring>


int main(){

	char num[105];
	int len, temp;
	bool carryFlag, borrowFlag;

	while ( scanf("%s", num) != EOF){

		carryFlag = borrowFlag = false;

		len = strlen(num);
		
		if(len == 1){

			if( num[0] == '1')
				printf("1\n");
			else if ( num[0] == '0')
				printf("0\n");
			else{
			
				temp = (num[0] - 48) * 2 - 2;
				printf("%d\n",temp); 

			}
			
			continue;
		}	

		temp = (num[len - 1] - 48) * 2 - 2;
		
		if(temp < 0){
			temp = 10 + temp;
			borrowFlag = true;
		}
		else if(temp > 9){
			
			temp = temp - 10;
			carryFlag = true;
		}				
		
		num[len - 1] = temp + 48;

		for( int i = len - 2; i >= 0; i-- ){

			temp = (num[i] - 48) * 2;
			
			if( carryFlag ){
				temp++;
				carryFlag = false;
 			
			}			
			else if( borrowFlag ){
				temp--;
				borrowFlag = false;
			}
			
			if(temp > 9){
			
				temp = temp - 10;
				carryFlag = true;
			}				
			else if(temp < 0){
				
				temp = 10 + temp;
				borrowFlag = true;
			}

			num[i] = temp + 48;
		}

		if(carryFlag)
			printf("1%s\n", num);
		else
			printf("%s\n", num);
	}

	return 0;

}
