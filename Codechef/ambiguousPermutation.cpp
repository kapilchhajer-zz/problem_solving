#include<iostream>
#include<cstdio>
#include<cstdlib>

#define gc() getchar_unlocked();

using namespace std;

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

	int num,*values,i;
	num=read_int();
	while(num!=0){
		values = (int *) malloc( sizeof(int) * (num+1));
		
		for(i=1;i<=num;i++)
			values[i]=read_int();
		
		for(i=1;i<=num;i++)
			if(values[values[i]]!=i)
				break;

		if(i!=num+1)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
			
		free(values);
		num=read_int();
	}

	return 0;
}
