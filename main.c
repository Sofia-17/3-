#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
int main(void) {
 int **m=NULL, q, err, x;
 err=Input("data.dat",&m,&q);
 if(err) printf("Error1\n");
 else {
  x=Check("data.dat",m,q);
  if(x) printf("Error2\n");
 }
  free(m); m=NULL;
  return 0;
}
