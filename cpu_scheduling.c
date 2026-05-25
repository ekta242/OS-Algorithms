# include <stdio.h>
# include <stdlib.h>    
# define MAX 100
# define QUANTUM 3
typedef struct process{
    int pid;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
    int arrival;
    int priority;
    int completion;
} Process;
 void copyProcess(Process dest[], Process src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
float fcfs(Process p[], int n){
    int time=0;
    float total_wait=0;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (p[i].arrival>p[j].arrival){
                Process temp=p[i];
                p[i]=p[j];
                p[j]=temp;  
            }
        }
    }
for(int i=0;i<n;i++){
    if (time<p[i].arrival)
        time=p[i].arrival;
        p[i].waiting=time-p[i].arrival;
        time+=p[i].burst;
        total_wait+=p[i].waiting;
    }
    return total_wait/n;
}