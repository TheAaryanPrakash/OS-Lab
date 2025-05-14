#include <stdio.h>

void main() {
    int n, i, bt[20], rt[20], wt[20], tat[20], tq, time = 0;
    int remain;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Copy of burst times for round robin use
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;
    int done = 0;
    for (i = 0; remain != 0;) {
        if (rt[i] > 0) {
            if (rt[i] > tq) {
                time += tq;
                rt[i] -= tq;
            } else {
                time += rt[i];
                wt[i] = time - bt[i];
                rt[i] = 0;
                tat[i] = time;
                remain--;
            }
        }
        i = (i + 1) % n;
    }

    float total_wt = 0, total_tat = 0;
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("Average Turnaround Time = %.2f", total_tat / n);
}
