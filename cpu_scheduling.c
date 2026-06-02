# include <stdio.h>
# include <stdlib.h>   
#include <limits.h> 
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
        found=0;
        for (int i=0;i<n;i++){
            if (p[i].arrival<=time &&p[i].remaining>0 && p[i].remaining<min_remain){
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
            p[shortest].waiting=p[shortest].completion-p[shortest].arrival-p[shortest].burst;
            if(p[shortest].waiting<0)
                p[shortest].waiting=0;
            total_time+=p[shortest].waiting;
        }
        }
    return total_time/n;
    }
float non_preemptive(Process p[],int n){
    int complete=0,time=0,highest;
    int visited[MAX]={0};
    float total_time=0;
    float total_wait=0;
    while(complete!=n){
        int max_priority=-1;
        highest=-1;
        for (int i=0;i<n;i++){
            if(p[i].arrival<=time && !visited[i])
            if (p[i].priority>max_priority){
                max_priority=p[i].priority;
                highest=i;
            }
        }
        if(highest==-1){
            time++;
            continue;}
        visited[highest]=1;
        p[highest].completion=time;
        p[highest].waiting=p[highest].completion-p[highest].arrival-p[highest].burst;
        time+=p[highest].burst;
        if(p[highest].waiting<0)
            p[highest].waiting=0;
        total_time+=p[highest].waiting;
        complete++;}
    return total_time/n;
    }
float round_robin(Process p[], int n) {
    int time = 0, complete = 0;
    int queue[MAX], front = 0, rear = 0;
    int in_queue[MAX] = {0};
    float total_time = 0;

    while (complete != n) {

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time &&
                !in_queue[i] &&
                p[i].remaining > 0) {

                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        if (front == rear) {
            time++;
            continue;
        }

        int i = queue[front++];
        in_queue[i] = 0;

        int exec = (p[i].remaining > QUANTUM)? QUANTUM: p[i].remaining;

        p[i].remaining -= exec;
        time += exec;

        for (int j = 0; j < n; j++) {
            if (p[j].arrival <= time && !in_queue[j] && p[j].remaining > 0 && j != i) {
                queue[rear++] = j;
                in_queue[j] = 1;
            }
        }

        if (p[i].remaining > 0) {
            queue[rear++] = i;
            in_queue[i] = 1;
        }
        else {
            complete++;
            p[i].completion = time;

            p[i].waiting =
                p[i].completion -
                p[i].arrival -
                p[i].burst;

            if (p[i].waiting < 0)
                p[i].waiting = 0;

            total_time += p[i].waiting;
        }
    }

    return total_time / n;
}
    
   int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[MAX];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter arrival time, burst time and priority for process %d: ", i + 1);
        scanf("%d %d %d",
              &p[i].arrival,
              &p[i].burst,
              &p[i].priority);

        p[i].remaining = p[i].burst;
    }

    Process t1[MAX], t2[MAX], t3[MAX], t4[MAX];

    copyProcess(t1, p, n);
    copyProcess(t2, p, n);
    copyProcess(t3, p, n);
    copyProcess(t4, p, n);

    float fcfs_avg = fcfs(t1, n);
    float srtf_avg = srtf(t2, n);
    float priority_avg = non_preemptive(t3, n);
    float rr_avg = round_robin(t4, n);

    printf("\nAverage waiting time for FCFS: %.2f\n", fcfs_avg);
    printf("Average waiting time for SRTF: %.2f\n", srtf_avg);
    printf("Average waiting time for Non-Preemptive Priority: %.2f\n", priority_avg);
    printf("Average waiting time for Round Robin: %.2f\n", rr_avg);

    float least = fcfs_avg;

    if (srtf_avg < least)
        least = srtf_avg;

    if (priority_avg < least)
        least = priority_avg;

    if (rr_avg < least)
        least = rr_avg;

    printf("Least average waiting time: %.2f\n", least);

    return 0;
}
