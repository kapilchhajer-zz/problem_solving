#include<iostream>
using namespace std;

void present( int num){

	if( num <= 1){
		if(num == 1)
			cout<<"2(0)";
		return ;
	}

	int c=1,p = 2,j=2;
	
	while( num >= p){
	
		p = p * j;
		c++;			
	}
	
	p = p/2;
	c--;
	j= num - p;
	if(c==1)
		cout<<"2";
	else{
	cout<<"2(";
	present(c);
	cout<<")";
	}
	if(j > 0)
	   cout<<"+";
	present(j);
	
}

int main(){

	int num[7] = {137,1315,73,136,255,1384,16385};
	
	for( int i = 0; i < 7; i++){ 
		cout<<num[i]<<"=";
		present(num[i]);
		cout<<endl;
	}
}
