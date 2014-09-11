#include<iostream>

using namespace std;

int main(){

	long int i=0,j;

	while(i >=  0){
		j = i;
		i++;
	}

	cout<<"largest value of i : "<<j<<endl;

	i=0;

	while(i <= 0){
		j = i;
		i--;
	}

	
	cout<<"Minimum value of i : "<<j<<endl;

	return 0;
}

