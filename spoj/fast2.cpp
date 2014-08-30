#include<cstdio>
#include<cstring>
int main(){
int t,n,q,i,j;
bool c;
scanf("%d",&q);
while(q--){
scanf("%d",&n);
char r[154],p[154],m[35]="1298074214633706835075030044377087";
for(i=0;i<152;i++)
r[i]='0';
r[152]='1';
r[153]='\0';
p[153] = '\0';
while(n>0){
c=false;
for(i=152; i>=0;i--){
t=r[i]-'0';
t=t+t;
if(i==152)
t++;
if(c){
c=false;
t++;
}
if(t>9){
c=true;
t=t-10;
} 
r[i]=t+'0';
}
n--;
while(1){
c=0;
for(i=152,j=33; i>=0;i--,j--){
t=r[i]-'0';
if(j>=0)
t=t-m[j]+'0';
if(c){c=0;t--;}
if(t<0){c=1;t=t+10;} 
p[i]=t+'0';}
if(c)break;strcpy(r,p);}	
}
for(i=0; i<=153 ;i++){
if(r[i]!='0'){
t=i;
break;
}
}
printf("%s\n",r+t);
}
return 0;
}
