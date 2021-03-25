#include<stdio.h>

int main()
{
 int k, n=5,res;
 for(k=1;k<=n;k++)
 {
  res = fact(k);
  printf("%d\n",res);
 }
 return 0;
}
int fact(n){
 int f=1,i;
 for(i=1;i<=n;i++)
 f=f*i;
 return f;
 }
