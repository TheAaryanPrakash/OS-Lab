#include <stdio.h>
#include <stdlib.h>

#define N 5

int chopstick[N] = {1, 1, 1, 1, 1}; // 1 = available, 0 = taken
int mutex = 1;
int eating = 0; // how many philosophers are currently eating

// Semaphore wait operation
void wait(int *s) {
    --(*s);
}

// Semaphore signal operation
void signal(int *s) {
    ++(*s);
}

// Pick up both left and right chopsticks
void take_chopsticks(int i) {
    wait(&chopstick[i]);
    wait(&chopstick[(i + 1) % N]);
}

// Put down both left and right chopsticks
void put_chopsticks(int i) {
    signal(&chopstick[i]);
    signal(&chopstick[(i + 1) % N]);
}

// Simulate eating
void eat(int i) {
    printf("Philosopher %d is eating\n", i + 1);
    printf("Philosopher %d finished eating\n", i + 1);
}

// Attempt to let philosopher eat, ensuring max simultaneous eaters are respected
void try_to_eat(int i, int maxEating) {
    wait(&mutex);

    if (chopstick[i] == 1 && chopstick[(i + 1) % N] == 1 && eating < maxEating) {
        take_chopsticks(i);
        eating++;
        eat(i);
        put_chopsticks(i);
        eating--;
    } else {
        printf("Philosopher %d cannot eat now (blocked)\n", i + 1);
    }

    signal(&mutex);
}

int main() {
    int mode, count, pos[5];

    printf("Enter total number of hungry philosophers: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Enter position of hungry philosopher %d (1-5): ", i + 1);
        scanf("%d", &pos[i]);
        pos[i]--; // adjust for 0-based index
    }

    while (1) {
        printf("\n1. Allow ONE philosopher to eat at a time\n");
        printf("2. Allow TWO philosophers to eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);

        if (mode == 3) break;

        int maxEating = (mode == 1) ? 1 : 2;

        for (int i = 0; i < count; i++) {
            printf("Philosopher %d is trying to eat...\n", pos[i] + 1);
            try_to_eat(pos[i], maxEating);
        }
    }

    return 0;
}
