//http://www.spoj.com/problems/CANDY/

#include<cstdio>

using namespace std;

int main(){

	int N, total, avg, move;

	scanf("%d",&N);

	while(N != -1){
		
		total = avg = move = 0;
		int Arr[N];

		for(int i = 0; i < N; i++){
			scanf("%d", Arr + i);
			total = total + Arr[i];
		}

		avg = total / N;

		if( avg * N != total){
				
			printf("-1\n");
		}
		else{

			for(int i = 0; i < N; i++){

				if(Arr[i] > avg){

					move = move + Arr[i] - avg;
				}
			}

			printf("%d\n",move);
		}
		
		
		scanf("%d",&N);
	}
	return 0;
}
