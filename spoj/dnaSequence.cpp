//http://www.spoj.com/problems/SAMER08D/

#include<cstdio>
#include<cstring>

using namespace std;


int main(){

	int dp[1001][1001], K, lenStringA, lenStringB;
	char A[1001], B[1001];

	scanf("%d",&K);

	while(K != 0){

		char match[1001][1001];

		scanf("%s %s",A,B);
			
		lenStringA = strlen(A);
		lenStringB = strlen(B);
		
		printf("\n");
		for(int i = 0; i <= lenStringA; i++){

			for(int j = 0; j <= lenStringB; j++){
			
				match[i][j] = '.';
				if(i == 0 || j == 0){

					dp[i][j] = 0;
				}
				else if( A[i - 1] == B[j - 1]){
					
					match[i][j] = 'd';
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{

					dp[i][j] = dp[i - 1][j] >= dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
					match[i][j] = dp[i - 1][j] >= dp[i][j - 1] ? 'u' : 'l';
						
				}
				printf(" %d ",dp[i][j]);
			}
			
			printf("\n");
		}
	
		printf("\n\n\n       ");
		for(int i = 1 ; i <= lenStringB; i++)
			printf("%c  ",B[i - 1]);

		printf("\n");
		
		for(int i = 0; i <= lenStringA; i++){

			for(int j = 0; j <= lenStringB; j++){
			
				if( j == 0 && i != 0)
					printf(" %c ",A[i - 1]);
				printf(" %c ",match[i][j]);
			}
			
			printf("\n");
		}

		int answer, count, p, l ;
		bool flag;

		for(int i = lenStringA ; i > 0; i --){

			answer = dp[i][lenStringB];
			count = 0;
			p = i;
			flag = true;

			for(int j = lenStringB; j > 0 && p > 0;  ){
	
				if(match[p][j] == 'd'){
					
					count++;
					p--;
					j--;
			
				}
				else if( (count == 0 || count >= K ) &&  match[p][j] == 'l'){

					count = 0;
					j--;
					
				}
				else if( (count == 0 || count >= K ) && match[p][j] == 'u'){
			
					count = 0;
					p--;
				}
				else{

					flag = false;
					break;
				}		

			}
			if( flag && ( count == 0 || count >= K ) )
				break; 
		}

		
		if( flag && ( count == 0 || count >= K ) )
			printf("%d\n", answer);
		else
			printf("0\n");
		scanf("%d",&K);
	}

	return 0;
}
