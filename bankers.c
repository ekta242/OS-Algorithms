# include <stdio.h>
# include <stdlib.h>
int main(){
    int  n,m=3;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int alloc[n][m],max[n][m];
    printf("Enter the allocation matrix:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the Max matrix");
    for(int i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);

        }
    }
    int avail[m];
    printf("Enter the available resources: ");
    for (int i=0;i<m;i++){ 
        scanf("%d",&avail[i]);
    }
    int need[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    int finish[n];
    int work[m];
    int safe_seq[n];
    int count=0;

    for (int i=0;i<n;i++){
        finish[i]=0;

    }
    for(i=0;i<m;i++){
        work[i]=avail[i];
    }
}