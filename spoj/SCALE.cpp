//http://www.spoj.com/problems/SCALE/

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

long long int  threePower[21], threePowerSum[21];
int side[21], oposite[21], m = 0, n = 0;
bool opositeFlag = false;

void represent( long long int num){

	int i;

	while( num != 0){

		for( i = 0; i < 21; i++){
			if( threePowerSum[i] >= num)
				break;

		}

		num = num - threePower[i];

		if( opositeFlag)
			oposite[n++] = i;
		else
			side[m++] = i;

		if( num < 0 ){

			num = num * (-1);
			opositeFlag = opositeFlag ^ true;
		}	


	}
}

int main(){

	threePower[0] = 1;
	threePowerSum[0] = 1;

	for( int i = 1; i < 21; i++){
		threePower[i] = threePower[i - 1] * 3;
		threePowerSum[i] = threePower[i] + threePowerSum[i -1];
	}

	long long int num;
	int N;

	scanf("%d %lld", &N , &num); 
	
	if( num > threePowerSum[N -1]){
		printf("-1\n");
		return 0;
	}

	represent(num);

	sort(side, side + m);
	sort(oposite , oposite + n);
	
	for( int i = 0; i < n; i++)
		printf("%d ",oposite[i] + 1);

	printf("\n");

	for( int i = 0; i < m; i++)
		printf("%d ",side[i] + 1);

	printf("\n");
	

	return 0;
}
