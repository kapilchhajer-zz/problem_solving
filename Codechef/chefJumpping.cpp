#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
 	char num[126];
	scanf("%s",num);
	int length,cal=0;
	length=strlen(num);

	for(int i=0;i<length;i++){
		cal+=num[i]-'0';
	}
	cal = cal%3;
	if((num[length-1]-'0')%2==0){
		if(cal==1)
			cal+=3;
		
	}
	else{
		if(cal==2)
			cal+=3;
	    }
	if( cal == 0 || cal == 1)
		printf("yes\n");
	else
		printf("no\n");
	
	
	return 0;
}
