#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"fun.h"

int Input(const char *fs, int ***m, int *q)
{FILE *f; int count=0, strcount=0, k,i,l; char str[256], num[256], *cina;
 f=fopen(fs,"r");
 if(f==NULL) return -1;
 while(fgets(str,256,f)) {
  strcount++;
  for(cina=str;(sscanf(cina,"%s%n",num,&k)==1);cina=cina+k) count++;
 }
 *q=strcount;
 rewind(f);
 *m=(int**)malloc((strcount+1)*sizeof(int*)+(count+strcount)*sizeof(int));
 (*m)[0]=(int*)((*m)+strcount+1); // кол-во чисел в первой строке
 (*m)[1]=(*m)[0]+(*q); // кол-во во второй строке


 for(l=1; (fgets(str,256,f)!=0)&&(l<=*q);l++) {
  for(i=0, cina=str;sscanf(cina,"%d%n",(*m)[l]+i,&k)==1;cina=cina+k,i++);
  (*m)[0][l-1]=i;
  if(l<(*q)) {
   (*m)[l+1]=(*m)[l]+i;
  }
 }
 return 0;
}
