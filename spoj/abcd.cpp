//http://www.spoj.com/problems/ABCD/

#include<cstdio>

using namespace std;


int main(){

	char in[100005], ch = 'E';
	int N, len;
	
	scanf("%d%s", &N, in);

	len = 2 * N;

	for( int i = 0; i < len - 1; i = i + 2){

		if( (in[i] == 'A' && in[i + 1] == 'B') || (in[i] == 'B' && in[i + 1] =='A') ){
		
			if(ch == 'C')
				printf("DC");
			else{
				printf("CD");
				ch = 'D';
			}

		}
		else if( (in[i] == 'A' && in[i + 1] == 'C') || (in[i] == 'C' && in[i + 1] =='A') ){
		
			if(ch == 'B')
				printf("DB");
			else{
				printf("BD");
				ch = 'D';
			}

		}
		else if( (in[i] == 'A' && in[i + 1] == 'D') || (in[i] == 'D' && in[i + 1] =='A') ){
		
			if(ch == 'B')
				printf("CB");
			else{
				printf("BC");
				ch = 'C';
			}

		}
		else if( (in[i] == 'B' && in[i + 1] == 'C') || (in[i] == 'C' && in[i + 1] =='B') ){

			if(ch == 'A')
				printf("DA");
			else{
				printf("AD");
				ch = 'D';
			}

		}
		else if( (in[i] == 'B' && in[i + 1] == 'D') || (in[i] == 'D' && in[i + 1] =='B') ){

			if(ch == 'A')
				printf("CA");
			else{
				printf("AC");
				ch = 'C';
			}
		}
		else if( (in[i] == 'C' && in[i + 1] == 'D') || (in[i] == 'D' && in[i + 1] =='C') ){

			if(ch == 'B')
				printf("AB");
			else{
				printf("BA");
				ch = 'A';
			}

		}

	}
	
	printf("\n");
	return 0;
}
