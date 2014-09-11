//http://www.spoj.com/SPOJ/problems/UCV2013C/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	unsigned long long int  D, total, F, B, M;

	scanf("%llu %llu %llu %llu" , &D, &F, &B, &M);

	while( D != 0 && F != 0 && B != 0 && M != 0){

		total = ( F * (F + 1) / 2  + 1) * B + M;
		
		if(total < D)
			printf("Farmer Cream will have %llu Bsf to spend.\n",  D - total + M);
		else
			printf("The firm is trying to bankrupt Farmer Cream by %llu Bsf.\n",total - D);


		
		scanf("%llu %llu %llu %llu" , &D, &F, &B, &M);

	}

	return 0;
}
