//http://www.spoj.com/problems/KNGCHECK/


#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

int main(){

	string in[9][9];
	int testCases, row, column, turn = 0;
	bool checkFlag;

	scanf("%d",&testCases);

	while( testCases-- ){

		turn++;
		checkFlag = false;

		for(int i = 1 ; i < 9 ; i++ ){

			for(int j = 1 ; j < 9 ; j++ ){

				cin>>in[i][j];

				if(in[i][j] == "BK"){
				
					row = i;
					column = j;
				}
			}
		}	

		for( int i = 1 ; i < 9 ; i++ ){
			
			for( int j = 1 ; j < 9 ; j++){

				if(in[i][j] == "-")
					continue;

				if(in[i][j] == "WP" && i - row == 1 && int(abs( double(column - j))) == 1 ){

					checkFlag = true;
					break;
				}
				else if(in[i][j] == "WK" &&  int( abs( double(i - row) ) ) <= 1 && int( abs( double (column - j) ) ) <= 1){
					checkFlag = true;
					break;
				}
				else if(in[i][j] == "WH"){

					int t = pow( i - row , 2 ) + pow( j - column , 2 );
					
					if(t == 5){
						checkFlag = true;
						break;
					}
				}
			}

			if(checkFlag)
				break;
		}

		if(checkFlag){
			printf("Case #%d: Check\n",turn);
		}
		else{
			printf("Case #%d: Not Check\n",turn);

		}
	}

	return 0;
}
