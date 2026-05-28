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

    
    for(i=0;i<m;i++){
        work[i]=avail[i];
    }
    while (count<n){
        int found=o;
        for(i=0;i<n;i++){
            if finish[i]==0){
                int j;
                for (j=0;j<m;j++){
                    if need[i][j]>work[j]
                    break;
                }
                if (j==m){
                    for (k=0;k<m;k++)
                        work[k]+=alloc[i][k];
                    
                    safe_seq[count++]=i;
                    finish[i]=1;    
                    found=1;
                }
            }    
        
        }
        if (!found)
            break;
    }
    printf("Allocation Matrix:\n");
    for(int i=0;i<n;i++){
        printf("P%d: ",i);
        for (int j=0;j<m;j++){
            printf("%4d ",alloc[i][j]);
        }
        printf("\n");
    }
    printf("Available Resources: ");
    for (int i=0;i<m;i++){
        printf("%4d ",avail[i]);
    }
    printf("\n");

    printf("Max Matrix:\n");
    for (int i=0;i<n;i++){  
        printf("P%d: ",i);
        for (int j=0;j<m;j++){
            printf("%4d ",max[i][j]);
        }
        printf("\n");
    }
    if(count==n){
        printf("System is in a safe state.\nSafe sequence: ");
        for (int i=0;i<n;i++){
            printf("P%d ",safe_seq[i]);
        }
        printf("\n");
        printf("Need Matrix:\n");
        for (int i=0;i<n;i++){
            printf("P%d: ",i);
            for (int j=0;j<m;j++){
                printf("%4d ",need[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("System is in DEADLOCK.\n");
        printf("Processes that are in deadlock: ");
        for (int i=0;i<n;i++){
            if (finish[i]==0){
                printf("P%d ",i);
            }
        }   
    }
    return 0;
}
