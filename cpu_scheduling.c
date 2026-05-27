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
    for (int i = 0; i < n; i++) 
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
float srtf(Process p[],int n){
    int complete=0,time=0,min_remain;
    int shortest=0,found=0;
    float total_time=0;
    while (complete!=n){
        min_remain=INT_MAX;
        found=0
        for (int i=0;i<n;i++){
            if (p[i].arrival<=time &&p[i].remaining>0 && p[i].remaing<min_remain){
                min_remain=p[i].remaining;
                shortest=i;
                found=1;
            }
        }
        if(!found){
            time++;
            continue;
        }
        p[shortest].remaining--;
        time++;
        if (p[shortest].remaining==0){
            complete++;
            p[shortest].completion=time;
            p[shortest].waiting=p[shortest].completion-p[shortest].arrival-p[shortest].burst
            if(p[shortest].waiting<0)
                p[shortest].waiting=0;
            total_time+=p[shortest].waiting;
        }
        }
    return total_time/n;
    }
}
