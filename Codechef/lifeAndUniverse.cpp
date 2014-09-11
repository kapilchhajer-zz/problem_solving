#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
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
int main()
{

int num=read_int();
while(num!=42){
printf("%d\n",num);
num=read_int();
}


return 0;
}
