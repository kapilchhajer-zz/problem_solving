#include<stdio.h>

int main()
{
	int withdraw;
	float balance;
	scanf("%d%f",&withdraw,&balance);
	if(withdraw+0.50<=balance && withdraw%5==0)
		printf("%.2f\n",balance-withdraw-0.50);
	else
		printf("%.2f\n",balance);

	return 0;
}
