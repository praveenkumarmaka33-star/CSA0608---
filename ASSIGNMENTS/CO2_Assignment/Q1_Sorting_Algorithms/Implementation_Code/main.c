#include <stdio.h>
#include <time.h>
#define N 100
void print(int a[], int n){ for(int i=0;i<n;i++) printf("%d ",a[i]); puts(""); }
void selection(int a[],int n,long *c,long *m){*c=*m=0; for(int i=0;i<n-1;i++){int k=i;for(int j=i+1;j<n;j++){(*c)++;if(a[j]<a[k])k=j;}if(k!=i){int t=a[i];a[i]=a[k];a[k]=t;(*m)++;}}}
void bubble(int a[],int n,long *c,long *m){*c=*m=0;for(int i=0;i<n-1;i++){int changed=0;for(int j=0;j<n-i-1;j++){(*c)++;if(a[j]>a[j+1]){int t=a[j];a[j]=a[j+1];a[j+1]=t;(*m)++;changed=1;}}if(!changed)break;}}
void insertion(int a[],int n,long *c,long *m){*c=*m=0;for(int i=1;i<n;i++){int key=a[i],j=i-1;while(j>=0){(*c)++;if(a[j]>key){a[j+1]=a[j];(*m)++;j--;}else break;}a[j+1]=key;(*m)++;}}
int main(){int sets[3][8]={{1,2,3,4,5,6,7,8},{8,7,6,5,4,3,2,1},{1,2,3,5,4,6,7,8}};char *names[]={"Already sorted","Reverse sorted","Nearly sorted"};for(int s=0;s<3;s++){printf("\\n%s: ",names[s]);print(sets[s],8);for(int alg=0;alg<3;alg++){int a[8];for(int i=0;i<8;i++)a[i]=sets[s][i];long c,m;if(alg==0)selection(a,8,&c,&m);else if(alg==1)bubble(a,8,&c,&m);else insertion(a,8,&c,&m);printf("%s comparisons=%ld movements/swaps=%ld result: ",alg==0?"Selection":alg==1?"Bubble":"Insertion",c,m);print(a,8);}}return 0;}