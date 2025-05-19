#include <stdio.h>

void main() {
    int numProcesses, userIndex = 0, systemIndex = 0;
    int processType, burstTimeInput;
    float totalWaitingTime, totalTurnaroundTime;

    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // Declare arrays
    int finalProcessOrder[numProcesses], userProcessIds[numProcesses], systemProcessIds[numProcesses];
    int userBurstTimes[numProcesses], systemBurstTimes[numProcesses], finalBurstTimes[numProcesses];
    int processTypeFlags[numProcesses]; // 1 = system, 0 = user
    int waitingTime[numProcesses], turnaroundTime[numProcesses];

    // Input process type and burst time
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter System/User process (1 for System / 0 for User): ");
        scanf("%d", &processType);

        printf("Enter burst time: ");
        scanf("%d", &burstTimeInput);

        if (processType == 1) {
            systemProcessIds[systemIndex] = i + 1;
            systemBurstTimes[systemIndex++] = burstTimeInput;
        } else {
            userProcessIds[userIndex] = i + 1;
            userBurstTimes[userIndex++] = burstTimeInput;
        }
    }

    // First, add system processes to final arrays
    for (int i = 0; i < systemIndex; i++) {
        finalProcessOrder[i] = systemProcessIds[i];
        finalBurstTimes[i] = systemBurstTimes[i];
        processTypeFlags[i] = 1;
    }

    // Then add user processes
    for (int i = 0; i < userIndex; i++) {
        finalProcessOrder[systemIndex + i] = userProcessIds[i];
        finalBurstTimes[systemIndex + i] = userBurstTimes[i];
        processTypeFlags[systemIndex + i] = 0;
    }

    // Calculate waiting time and turnaround time
    waitingTime[0] = 0;
    turnaroundTime[0] = finalBurstTimes[0];
    totalWaitingTime = waitingTime[0];
    totalTurnaroundTime = turnaroundTime[0];

    for (int i = 1; i < numProcesses; i++) {
        waitingTime[i] = waitingTime[i - 1] + finalBurstTimes[i - 1];
        turnaroundTime[i] = waitingTime[i] + finalBurstTimes[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Output results
    printf("\nProcess\tType\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\n",
               finalProcessOrder[i],
               (processTypeFlags[i] == 1) ? "System" : "User",
               finalBurstTimes[i],
               waitingTime[i],
               turnaroundTime[i]);
    }

    printf("\nAverage waiting time = %.2f", totalWaitingTime / numProcesses);
    printf("\nAverage turnaround time = %.2f\n", totalTurnaroundTime / numProcesses);
}
