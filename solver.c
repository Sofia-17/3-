#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"fun.h"

int Check(const char *fs, int **m, int q) { 
FILE *f;
 f = fopen(fs,"w");
 if(f == NULL) return -1;
 int i,k,l=-1, sum = 0, p = 0;
 for(i=1;i<=q;i++) {
  for(k=0;k<m[0][i-1];k++) { 
    sum+=m[i][k];}
    p+=m[0][i-1];
 }
 for(i=1;i<=q;i++) {
  for(k=0;k<m[0][i-1];k++) {
   if(sum==m[i][k]*p) {l=k; goto qr;}
  }
 }
 qr:;
 if(l!=-1) {
   for(i=1;i<=q;i++) {
   for(k=l;k<(m[0][i-1]-1);k++) {m[i][k]=m[i][k+1];}
   if(l<m[0][i-1]) m[0][i-1]--;
  }
 }
 for(i=1;i<=q;i++) {
  for(k=0;k<m[0][i-1];k++) {fprintf(f,"%d ", m[i][k]);}
  fprintf(f,"\n");
 }
 fclose(f);
 return 0;
}
