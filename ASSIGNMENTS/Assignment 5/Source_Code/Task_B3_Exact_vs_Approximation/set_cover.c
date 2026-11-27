/* CO5 B3: Exact minimum set cover vs greedy maximum-new-coverage.
   Input is built into main for reproducible experiments.
   Exact search enumerates centre subsets; greedy repeatedly chooses the
   centre covering the most currently uncovered zones.
*/
#include <stdio.h>
#define MAXC 20
#define MAXZ 20
int C,Z, cover[MAXC][MAXZ];
long long exactStates, greedySteps;
int bestCount, bestMask;
int coversAll(int mask){
    for(int z=0;z<Z;z++){
        int hit=0;
        for(int c=0;c<C;c++) if((mask>>c)&1 && cover[c][z]) hit=1;
        if(!hit) return 0;
    }
    return 1;
}
void exactSolve(void){
    bestCount=C+1; bestMask=0; exactStates=0;
    unsigned int limit=1u<<C;
    for(unsigned int mask=0;mask<limit;mask++){
        exactStates++;
        int count=__builtin_popcount(mask);
        if(count<bestCount && coversAll((int)mask)){bestCount=count;bestMask=(int)mask;}
    }
}
void greedySolve(void){
    int uncovered[MAXZ], selected[MAXC]={0}, count=0;
    for(int z=0;z<Z;z++) uncovered[z]=1;
    greedySteps=0;
    while(1){
        int remaining=0;
        for(int z=0;z<Z;z++) remaining+=uncovered[z];
        if(!remaining) break;
        int best=-1,bestNew=0;
        for(int c=0;c<C;c++) if(!selected[c]){
            int newly=0;
            for(int z=0;z<Z;z++) if(uncovered[z] && cover[c][z]) newly++;
            if(newly>bestNew){bestNew=newly;best=c;}
        }
        greedySteps++;
        if(best<0 || bestNew==0){printf("Greedy: no complete cover exists\n");return;}
        selected[best]=1; count++;
        for(int z=0;z<Z;z++) if(cover[best][z]) uncovered[z]=0;
        printf("  Greedy choice %d covers %d new zones\n",best+1,bestNew);
    }
    printf("Greedy cover size: %d\n",count);
}
void setInstance(int zones,int centres,int data[MAXC][MAXZ]){
    Z=zones; C=centres;
    for(int c=0;c<C;c++) for(int z=0;z<Z;z++) cover[c][z]=data[c][z];
}
void run(char *name,int zones,int centres,int data[MAXC][MAXZ]){
    printf("\n%s (zones=%d, centres=%d)\n",name,zones,centres);
    setInstance(zones,centres,data);
    exactSolve();
    printf("Exact optimum: %d; exact subsets examined: %lld; selected centres:",bestCount,exactStates);
    for(int c=0;c<C;c++) if((bestMask>>c)&1) printf(" %d",c+1);
    printf("\nGreedy trace:\n");
    greedySolve();
    printf("Greedy selection steps: %lld\n",greedySteps);
}
int main(void){
    int d1[MAXC][MAXZ]={{0}},d2[MAXC][MAXZ]={{0}},d3[MAXC][MAXZ]={{0}},d4[MAXC][MAXZ]={{0}};
    /* Case 1: greedy = optimum: {1,2,3,4}, centres {1,2},{3,4},{1,3},{2,4}. */
    int x1[4][4]={{1,1,0,0},{0,0,1,1},{1,0,1,0},{0,1,0,1}};
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)d1[i][j]=x1[i][j];
    /* Case 2: optimum 2 and greedy also 2. */
    int x2[4][6]={{1,1,1,0,0,0},{0,0,0,1,1,1},{1,0,0,1,0,0},{0,1,0,0,1,0}};
    for(int i=0;i<4;i++)for(int j=0;j<6;j++)d2[i][j]=x2[i][j];
    /* Case 3 counterexample: centre 1 covers zones 1-4 (4 zones);
       centres 2 and 3 cover 1,2,5 and 3,4,6 respectively.
       Greedy takes centre 1, then needs both remaining centres (3 total);
       optimum takes centres 2 and 3 (2 total). */
    int x3[3][6]={{1,1,1,1,0,0},{1,1,0,0,1,0},{0,0,1,1,0,1}};
    for(int i=0;i<3;i++)for(int j=0;j<6;j++)d3[i][j]=x3[i][j];
    /* Larger 8-zone, 8-centre instance. */
    int x4[8][8]={{1,1,1,0,0,0,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,0,0,0,1,1},{1,0,0,1,0,0,1,0},{0,1,0,0,1,0,0,1},
      {0,0,1,0,0,1,1,0},{1,1,0,0,0,1,0,0},{0,0,1,1,0,0,0,1}};
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)d4[i][j]=x4[i][j];
    run("Instance 1",4,4,d1); run("Instance 2",6,4,d2);
    run("Instance 3 (greedy counterexample)",6,3,d3);
    run("Larger instance",8,8,d4);
    return 0;
}
