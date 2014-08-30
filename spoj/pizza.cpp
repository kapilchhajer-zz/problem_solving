//http://www.spoj.com/problems/EGYPIZZA/
//
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;


int main(){

	int N, countHalf, countThreeFourth, countOneFourth, count = 1;
	
	countHalf = countThreeFourth = countOneFourth = 0;
	scanf("%d", &N);

	string in[N];


	for(int i = 0; i < N; i++){
		cin>>in[i];

		if(in[i] == "1/2")
			countHalf++;
		else if( in[i] == "1/4")
			countOneFourth++;
		else 
			countThreeFourth++;
	}

	count = count + countHalf / 2;

	countHalf = countHalf % 2;

	if ( countHalf && countOneFourth >= 2){
		count++ ; 
		countHalf = countHalf - 1;
		countOneFourth = countOneFourth - 2;
	}
	
	if(countHalf > 0)
		count++;

	count = count + countThreeFourth;

	if( countOneFourth > countThreeFourth){

		countOneFourth = (countOneFourth - countThreeFourth);
		count = count + (countOneFourth / 4);

		if ( countOneFourth % 4 != 0)
			count++;
	}

	printf("%d\n",count);
	return 0;
}
