#include <stdio.h>

void main() {
    int n, iu = 0, is = 0, i, b;
    float wt_avg, tat_avg;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], up[n], sp[n], ubt[n], sbt[n], bt[n], u[n], wt[n], tat[n];

    for (int j = 0; j < n; j++) {
        printf("Enter System/User process (1 for System / 0 for User): ");
        scanf("%d", &i);
        printf("Enter burst time: ");
        scanf("%d", &b);

        if (i == 1) {
            sp[is] = j + 1;
            sbt[is++] = b;
        } else {
            up[iu] = j + 1;
            ubt[iu++] = b;
        }
    }

    // Merge system processes first
    for (int j = 0; j < is; j++) {
        p[j] = sp[j];
        bt[j] = sbt[j];
        u[j] = 1;  // System
    }

    // Then user processes
    for (int j = 0; j < iu; j++) {
        p[j + is] = up[j];
        bt[j + is] = ubt[j];
        u[j + is] = 0;  // User
    }

    wt[0] = 0;
    tat[0] = bt[0];
    wt_avg = wt[0];
    tat_avg = tat[0];

    for (int j = 1; j < n; j++) {
        wt[j] = wt[j - 1] + bt[j - 1];
        tat[j] = wt[j] + bt[j];
        wt_avg += wt[j];
        tat_avg += tat[j];
    }

    printf("Process\tSystem/User\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int j = 0; j < n; j++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[j], u[j], bt[j], wt[j], tat[j]);
    }

    printf("\nAverage waiting time = %.2f", wt_avg / n);
    printf("\nAverage turnaround time = %.2f\n", tat_avg / n);
}
