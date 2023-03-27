#include<stdio.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
};

void priority_scheduling(struct Process proc[], int n) {
    int i, j;
    struct Process temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(proc[j].priority > proc[j+1].priority) {
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
            else if(proc[j].priority == proc[j+1].priority && proc[j].arrival_time > proc[j+1].arrival_time) {
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;
    waiting_time[0] = 0;
    turnaround_time[0] = proc[0].burst_time;
    for(i=1; i<n; i++) {
        waiting_time[i] = waiting_time[i-1] + proc[i-1].burst_time - (proc[i].arrival_time - proc[i-1].arrival_time);
        if(waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }
        turnaround_time[i] = waiting_time[i] + proc[i].burst_time;
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Process\tBurst Time\tPriority\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].priority, proc[i].arrival_time, waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time/n);
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for(i=0; i<n; i++) {
        printf("Enter the burst time, priority, and arrival time of process %d: ", i+1);
        scanf("%d%d%d", &proc[i].burst_time, &proc[i].priority, &proc[i].arrival_time);
        proc[i].pid = i+1;
    }
    priority_scheduling(proc, n);
    return 0;
}

