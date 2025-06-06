#include <stdio.h>

void main() {
    int n, i, j, bt[20], p[20], pr[20], wt[20], tat[20], temp;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Priority for Process %d (Lower number = Higher priority): ", i + 1);
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    // Sorting processes by priority
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    float wta = 0, tata = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wta += wt[i];
        tata += tat[i];
    }

    wta /= n;
    tata /= n;

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", wta);
    printf("\nAverage Turnaround Time = %.2f", tata);
}
