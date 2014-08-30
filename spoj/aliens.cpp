//http://www.spoj.com/problems/ALIEN/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define gc() getchar_unlocked();

int read_int() {

    register char c = gc();

    while(c < '0' || c > '9') c = gc();

    int ret = 0;

    while(c >= '0' && c <= '9') {
	
	ret = 10 * ret + c - 48;
    	c = gc();
    }
	return  ret;
}
int main()
{
	int testCases, noOfStation, maxPersons, *array;
	testCases = read_int();

	while(testCases--)
	{
		noOfStation = read_int();
		maxPersons = read_int();
		array = (int *) malloc( noOfStation * sizeof(int));
		for(int i = 0; i < noOfStation; i++)
			array[i] = read_int();

		int sum = 0, j = 0, count = 0, finalSum = 0, finalCount = 0;
		for(int i = 0; i < noOfStation; i++)
		{
			while(j < noOfStation && sum <= maxPersons)
			{
				sum = sum + array[j];
				j++;
			}
		
			if(sum > maxPersons)
			{
				j--;
				sum = sum - array[j];
			}
			
			count = j - i;

			if(count > finalCount)
			{
				finalCount = count;
				finalSum = sum;
			}
			else if(count == finalCount && finalSum > sum)
				finalSum = sum;	
				
			sum = sum - array[i];
		}
		printf("%d %d\n",finalSum,finalCount);
		free(array);
	}
	return 0;
}



