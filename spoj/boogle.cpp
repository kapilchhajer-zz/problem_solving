//http://www.spoj.com/problems/BOGGLE/

#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){

	int N, j;	
	map< string , int> myMap;

	scanf("%d ", &N);
	
	string str[N][52];
	char st[10000], myString[100], ch;
	int s[N],length[N][52], limit, max = 0, temp, size, start, end,k;

	for( int i = 0; i < N; i++ ){
		
		start = 0;
		end = -1;
		j = 0;
		k = 0;

		ch = getchar();

		while(ch != '\n'){

			st[j] = ch;
			
			if(ch == ' '){

				if( start > end){
					start = j+1;
					end = j;
				}
				else{
					length[i][k] = end - start + 1;
					strncpy (myString, st + start , end - start + 1 );
					myString[end - start + 1] = '\0';
					str[i][k] = myString;
					myMap[str[i][k]]++;
					k++;
					start = j+1;
					 end = j;
				}
			
			}
			else{
				end++;
			}
			j++;
			ch = getchar();
		}		
		
		if( start <= end){
			length[i][k] = end - start + 1;
			strncpy (myString, st + start , end - start + 1 );
			myString[end - start + 1] = '\0';
			str[i][k] = myString;
			myMap[str[i][k]]++;
			k++;
		}
		s[i] = k;
		
	}

	for(int i = 0 ; i < N ; i++){

		temp = 0;
		limit = s[i];
		for(int j = 0 ; j < limit ; j++){
		
			if( myMap[str[i][j]] == 1 ){

				size = length[i][j];
				
				if( size <= 6){
				
					if( size < 4)
						temp++;
					else
						temp += size - 3;
				}
				else if(size == 7){
				
					temp += 5;
				}
				else{

					temp += 11;
				}					
			}
		}

		if( temp > max)
			max = temp;
	}
	
	printf("%d\n", max);
	
	return 0;
}
