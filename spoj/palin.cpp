//http://www.spoj.com/problems/PALIN/

#include<cstdio>
#include<cstring>

using namespace std;

int main(){

	long int testCases, length, i, j, left, right;
	char in[1000001];
	bool changeFlag, flag;

	scanf("%ld",&testCases);

	while(testCases--){

		scanf("%s",in);

		changeFlag = false;
		flag = false;
		length = strlen(in);
					
		for( i = 0 , j = length - 1; i < length ; i++, j--){

			left = in[i] - 48 ;
			right = in[j] - 48;

			if( i == 0 )
				right++;

			if(changeFlag){

				if( i >= j)
					break;
		
				if ( left > right)
					changeFlag = false;

			}
		
			if( left <  right  && i <= j ){
				changeFlag = true;
			}
		
		

		

			if( i >= j ){
			
				in[i] = in[j];	
			}
		}
		
		if(!changeFlag){

			printf("%s\n",in);
			continue;
		}

		if( length % 2 == 0 ){

			i = length / 2  - 1 ;
			j = i + 1;
		}
		else{

			i = j = length / 2  ; 
		}
		
		for( ; i >= 0; i--, j++){

			left = in[i] - 48;

			if( changeFlag ){

				left++;
				
				if( left == 10 ){

					in[i] = '0';
					
					if(i == 0)
						flag = true;
				}
				else{
					
					in[i] = left + 48;
					changeFlag = false;
				}
			}

			in[j] = in[i];
		}
		
		if(flag){
			printf("1");
			for( i = 1; i < length ;i++)
				printf("0");
			printf("1\n");	
			
		}
		else
			printf("%s\n",in);
	
	}
	return 0;
}
