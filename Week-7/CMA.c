#include <stdio.h>

#define MAX 100

// Prints the allocation result
void printAllocation(int allocation[], int processes) {
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

// First Fit Memory Allocation
void firstFit(int blocks[], int blockCount, int processes[], int processCount) {
    int allocation[MAX];
    
    // Initially all processes are not allocated
    for (int i = 0; i < processCount; i++)
        allocation[i] = -1;

    // Try to allocate each process
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break; // Stop once allocated
            }
        }
    }

    printf("\n--- First Fit Allocation ---\n");
    printAllocation(allocation, processCount);
}

// Best Fit Memory Allocation
void bestFit(int blocks[], int blockCount, int processes[], int processCount) {
    int allocation[MAX];
    for (int i = 0; i < processCount; i++)
        allocation[i] = -1;

    for (int i = 0; i < processCount; i++) {
        int best = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blocks[j] >= processes[i]) {
                if (best == -1 || blocks[j] < blocks[best])
                    best = j;
            }
        }

        if (best != -1) {
            allocation[i] = best;
            blocks[best] -= processes[i];
        }
    }

    printf("\n--- Best Fit Allocation ---\n");
    printAllocation(allocation, processCount);
}

// Worst Fit Memory Allocation
void worstFit(int blocks[], int blockCount, int processes[], int processCount) {
    int allocation[MAX];
    for (int i = 0; i < processCount; i++)
        allocation[i] = -1;

    for (int i = 0; i < processCount; i++) {
        int worst = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blocks[j] >= processes[i]) {
                if (worst == -1 || blocks[j] > blocks[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            blocks[worst] -= processes[i];
        }
    }

    printf("\n--- Worst Fit Allocation ---\n");
    printAllocation(allocation, processCount);
}

int main() {
    int blockCount, processCount;
    int originalBlocks[MAX], blockCopy[MAX], processes[MAX];

    // Input blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);
    printf("Enter sizes of the blocks:\n");
    for (int i = 0; i < blockCount; i++)
        scanf("%d", &originalBlocks[i]);

    // Input processes
    printf("Enter number of processes: ");
    scanf("%d", &processCount);
    printf("Enter sizes of the processes:\n");
    for (int i = 0; i < processCount; i++)
        scanf("%d", &processes[i]);

    // First Fit
    for (int i = 0; i < blockCount; i++)
        blockCopy[i] = originalBlocks[i];
    firstFit(blockCopy, blockCount, processes, processCount);

    // Best Fit
    for (int i = 0; i < blockCount; i++)
        blockCopy[i] = originalBlocks[i];
    bestFit(blockCopy, blockCount, processes, processCount);

    // Worst Fit
    for (int i = 0; i < blockCount; i++)
        blockCopy[i] = originalBlocks[i];
    worstFit(blockCopy, blockCount, processes, processCount);

    return 0;
}
