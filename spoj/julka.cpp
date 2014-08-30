//http://www.spoj.com/problems/JULKA/

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){

	char apple[105], extra[105],diff[105];
	int testCases = 10;
	bool carryFlag, leadingZeroFlag;

	while( testCases-- ){

		scanf("%s %s",apple,extra);
		
		int length1, length2, temp, first, second, div;

		length1 = strlen(apple);
		length2 = strlen(extra);


		diff[length1] = '\0';
		carryFlag = false;

		for(int i = length1 - 1, j = length2 - 1 ; i >= 0 ; i-- , j--){

			first = apple[i] - '0';

			if( j >= 0)
				second = extra[j] - '0';	
			else		
				second = 0;
			
			temp = first - second;
			
			if(carryFlag){
				carryFlag = false;
				temp--;
			}

			if(temp < 0){
				carryFlag = true;
				temp = temp + 10;
			} 
			
			diff[i]	= temp + '0' ;
		}

		//printf("%s\n", diff);
		
		temp = 0;
		
		for(int i = 0; i < length1 ; i++){


			temp = temp * 10 + diff[i] - '0';
			div  =  temp / 2;
			temp = temp % 2;
			apple[i] = div + '0';
		} 
		
		carryFlag = false;

		for(int i = length1 - 1, j = length2 - 1; i >= 0; i-- , j--){

			first = apple[i] - '0';

			if( j >= 0)
				second = extra[j] - '0';	
			else		
				second = 0;
			
			temp = first + second;
			
			if(carryFlag){
				carryFlag = false;
				temp++;
			}

			if(temp > 9){
				carryFlag = true;
				temp = temp - 10;
			} 
			
			diff[i] = temp + '0' ;
		}

		leadingZeroFlag = true;

		for(int i = 0; i < length1; i++){

			if(!leadingZeroFlag){
					
				temp = i;
				break;
			}

			if( diff[i] != '0'){
				leadingZeroFlag = false;
				i--;
			}
		}

		printf("%s\n",diff + temp);

		leadingZeroFlag = true;

		for(int i = 0; i < length1; i++){

			if(!leadingZeroFlag){
					
				temp = i;
				break;
			}

			if( apple[i] != '0'){
				leadingZeroFlag = false;
				i--;
			}
		}

		printf("%s\n",apple + temp);

 
	}

	return 0;
}
