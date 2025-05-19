#include <stdio.h>
#include <stdbool.h>

#define DISK_SIZE 100

int main() {
    int disk[DISK_SIZE] = {0};  // All disk blocks initially free
    int start, length, i, choice;

    while (1) {
        printf("\nEnter starting block and length of the file: ");
        scanf("%d%d", &start, &length);

        // Check if range is valid
        if (start < 0 || start >= DISK_SIZE || (start + length) > DISK_SIZE) {
            printf("Invalid input. Blocks out of disk range.\n");
        } else {
            bool allocated = true;

            // Check if all required blocks are free
            for (i = start; i < start + length; i++) {
                if (disk[i] == 1) {
                    allocated = false;
                    break;
                }
            }

            // Allocate blocks if possible
            if (allocated) {
                for (i = start; i < start + length; i++) {
                    disk[i] = 1;
                }
                printf("File allocated from block %d to %d.\n", start, start + length - 1);
            } else {
                printf("File cannot be allocated sequentially. Some blocks are already occupied.\n");
            }
        }

        // Prompt user to continue
        printf("Allocate another file? (1: yes / 0: no): ");
        scanf("%d", &choice);
        if (choice == 0) break;
    }

    return 0;
}
