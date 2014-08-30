//http://www.spoj.com/problems/EDIT/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){

	bool first, second, temp, temp1;
	int count1 ,count0;
	char str[1001];

	while( scanf("%s" , str) != EOF ){

		count1 = count0 = 0;
		first = true;
		second = false;
		for( int i = 0; str[i] != '\0'; i++){

			if(  str[i] >= 'a' && str[i] <= 'z' )
				temp = true;
			else
				temp = false;

			temp1 = temp ^ first;

			if( temp1)
				count0++;
			
			temp1 = temp ^ second;

			if( temp1)
				count1++;
			
			temp = first;
			first = second;
			second = temp;
		} 

		if( count0 < count1)
			printf("%d\n",count0);
		else
			printf("%d\n",count1);

	}

	return 0;
}
