#include<stdio.h>
#include<stdlib.h>

#define gc() getchar_unlocked();

int read_int() {
    register char c = gc();
    while(c<'0' || c>'9') c = gc();
    int ret = 0;
    while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
    }
	return  ret;
}


int main(){
	
	int rounds;
	rounds = read_int();

	int score1=0,score2=0,diff,lead=0,lead1=0,lead2=0,temp;

	while(rounds--){
		temp=read_int();
		score1 += temp;
		temp=read_int();
		score2 += temp;

		diff = abs(score1-score2);
		if(diff>lead){
			lead=diff;
			if(score1 > score2)	
				lead1 = lead > lead1 ? lead : lead1 ;		
			else
				lead2 = lead > lead2 ? lead : lead2 ; 
		}

	}
	
	if(lead1>lead2)
		printf("1 %d\n",lead1);
	else
		printf("2 %d\n",lead2);

		
	return 0;
}
