//http://www.spoj.com/problems/VUDBOL5/

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){


	unsigned long long int N, part[4], A, B, C, D, area, sum, sum1, sum2, share11, share12, share21, share22;
	bool impossibleFlag;

	scanf("%llu %llu %llu %llu %llu", &N, &part[0], &part[1], &part[2], &part[3]);
	A = part[0];
	B = part[1];
	C = part[2];
	D = part[3];

	while(! (N == 0 && A == N && A == B && A == C && A == D) ){

		impossibleFlag = false;
		area = N * N * N;
		sum  = A + B + C + D;

		if( sum != area){
			impossibleFlag = true;
		}
		else{
			if( !((A / N) * N == A && (B / N) * N == B && (C / N) * N == C && (D / N) * N == D) ){			
				impossibleFlag = true;
			}
			else{
				sort(part, part + 4);
					
				for(int i = 0; i < 4; i++)
					part[i] = part[i] / N;

				if( part[0] * part[3] == part[1] * part[2]){

					sum1 = part[3] + part[2];
					share11 = (part[3] * N )/ sum1;
					share12 = (part[2] * N )/ sum1;
					sum2 = part[3] + part[1];
					share21 = (part[3] * N )/ sum2;
					share22 = (part[1] * N )/ sum2;

					if( !(share11 + share12 == N && share21 + share22 == N))
						impossibleFlag = true;
				}
				else{
					impossibleFlag = true;
				}
			}
		}

		if(impossibleFlag)
			printf("Impossible\n");
		else
			printf("Possible\n");

		scanf("%llu %llu %llu %llu %llu", &N, &part[0], &part[1], &part[2], &part[3]);
		A = part[0];
		B = part[1];
		C = part[2];
		D = part[3];
	}
	
	return 0;
}	
