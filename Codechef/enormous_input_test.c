#include<stdio.h>

int main(){

	int input,number,divisor,count=0;

	scanf("%d%d",&number,&divisor);

	while(number--){
		scanf("%d",&input);
		if(input%divisor==0)
			count++;
	}

	printf("%d\n",count);
	return 0;
}
