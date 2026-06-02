# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define CYLINDERS 5000
# define N 10
void sort (int a[],int n){
    for(int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
    int sstf(int req[],int n,int head){
        int total=0,cur=head;
        int visited[N]={0};
        for (int s=0;s<n;s++){
            int min=1e9,idx=1;
            for(int i=0;i<n;i++){
                if (!visited[i]){
                    int d=abs(cur-req[i]);
                    if (d<min){
                        min=d;
                        idx=i;
                    }
                }
            }
            visited[idx]=1;
            total+=min;
            cur=req[idx];
        }
        return total;
    }
    int look(int req[],int n,int head){
        int a[N];
        for (int i=0;i<n;i++){
            a[i]=req[i];
        }
        sort(a,n);
        int total=0,cur=head;

        for (int i=0;i<n;i++){
            if (a[i]>=head){
                total+=abs(cur-a[i]);
                cur=a[i];
            }
        }
        for (int i=n-1;i>=0;i--){
            if (a[i]<head){
                    total+=abs(cur-a[i]);
                    cur=a[i];
                }
        }
        return total;
    }
    int cscan(int req[],int n,int head){
        int a[N];
        for (int i=0;i<n;i++){
            a[i]=req[i];
        }
        sort(a,n);
        int total=0,cur=head;

        for (int i=0;i<n;i++){
            if (a[i]>=head){
                total+=abs(cur-a[i]);
                cur=a[i];
            }
        }
        total+=abs(cur-(CYLINDERS-1));
        cur=CYLINDERS-1;

        total+=abs(cur-0);
        cur=0;

        for (int i=0;i<n;i++){
            if (a[i]<head){
                    total+=abs(cur-a[i]);
                    cur=a[i];
                }
        }
        return total;
    }
    int main(){
        int req[N];
        srand(time(0));
        for (int i=0;i<N;i++){
            req[i]=rand()%CYLINDERS;
        }
        int head=rand()%CYLINDERS;
        printf("Head: %d\n",head);
        printf("Requests: ");
        for (int i=0;i<N;i++){
            printf("%d ",req[i]);
        }
        printf("\nSSTF Total Head Movement: %d\n",sstf(req,N,head));
        printf("LOOK Total Head Movement: %d\n",look(req,N,head));
        printf("C-SCAN Total Head Movement: %d\n",cscan(req,N,head));
        return 0;
    }

