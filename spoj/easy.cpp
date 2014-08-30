#include<cstdio>
#define K printf
#define LL unsigned long long
void p(LL n){if(n<2){if(n==1)K("2(0)");return;} LL c=1,L=2,j=2;while(n>=L){L*=j;c++;}L/=2;c--;j=n-L;if(c==1)K("2");else{K("2(");p(c);K(")");}if(j>0)K("+");p(j);}
int main(){LL n;while(scanf("%llu",&n)!=EOF){K("%llu=",n);p(n);K("\n");}}
