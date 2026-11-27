#include <stdio.h>
#include <string.h>
typedef struct {char tool[12], technician[12], issue[20], bay[12];} Record;
int search(Record a[],int n,const char *key,int *count){*count=0;for(int i=0;i<n;i++){(*count)++;if(strcmp(a[i].tool,key)==0)return i;}return -1;}
int main(){Record a[]={{"T-101","TECH-01","09:00","BAY-A"},{"T-184","TECH-07","09:25","BAY-C"},{"T-220","TECH-03","10:10","BAY-B"},{"T-305","TECH-11","10:30","BAY-D"}};int n=4,c,pos;char *tests[]={"T-101","T-220","T-305","T-999"};for(int k=0;k<4;k++){pos=search(a,n,tests[k],&c);if(pos>=0)printf("%s held by %s at %s; comparisons=%d\\n",tests[k],a[pos].technician,a[pos].bay,c);else printf("%s not found; comparisons=%d\\n",tests[k],c);}return 0;}