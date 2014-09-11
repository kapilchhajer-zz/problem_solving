//http://www.codechef.com/problems/VOTERS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

int main(){

	long int N1,N2,N3,*first,*second,*third,output[50000];

	scanf("%ld %ld %ld",&N1,&N2,&N3);

	first = (long int *) malloc( (N1 + 1) * sizeof(long int));
	second = (long int *) malloc( (N2 + 1) * sizeof(long int));
	third = (long int *) malloc( (N3 + 1) * sizeof(long int));
	
	first[N1] = LONG_MAX;
	second[N2] = LONG_MAX;
	third[N3]  = LONG_MAX;

	for(int i = 0; i < N1; i++)
		scanf(" %ld ",first + i);

	for(int i = 0; i < N2; i++)
		scanf(" %ld ",second + i);

	for(int i = 0; i < N3; i++)
		scanf(" %ld ",third + i);


	long int firstPtr, secondPtr, thirdPtr, outputPtr, tempFirst, tempSecond, tempThird, match, count=0;

	firstPtr = secondPtr = thirdPtr = outputPtr = 0;
	tempFirst = first[firstPtr];
	tempSecond = second[secondPtr];
	tempThird = third[thirdPtr];
	
	while(true){

		if(tempFirst == tempSecond || tempFirst == tempThird)
			match = tempFirst;
		else if( tempSecond == tempThird)
			match = tempSecond;
		else{
			if(tempFirst < tempSecond){

				if(tempFirst < tempThird)
					tempFirst = first[++firstPtr];
				else
					tempThird = third[++thirdPtr];
			}
			else{

				if(tempSecond < tempThird)
					tempSecond = second[++secondPtr];
				else
					tempThird = third[++thirdPtr];
			}
			continue;
		}

		if(match >= tempFirst)
			tempFirst = first[++firstPtr];

		if(match >= tempSecond)	
			tempSecond = second[++secondPtr];

		if(match >= tempThird)
			tempThird = third[++thirdPtr];
		 
		if(match == LONG_MAX){
			output[outputPtr++] = -1;
			break;
		}
		output[outputPtr++] = match;
		count++;
	}

	outputPtr = 0;
	printf("%ld\n",count);

	while(output[outputPtr] != -1){
		printf("%ld\n",output[outputPtr++]);
	}

	return 0;
}
