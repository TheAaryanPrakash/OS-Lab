#include <stdio.h>

#define MAX 10

int total, hungry[MAX], num_hungry;
int state[MAX];
int mutex = 1;

void wait() {
    mutex--;
}

void signal() {
    mutex++;
}

int can_eat(int st[], int p) {
    int left = (p + total - 1) % total;
    int right = (p + 1) % total;
    return (st[left] != 2 && st[right] != 2);
}

void one_at_a_time(int st[]) {
    int eaten = 0;

    while (eaten < num_hungry) {
        for (int i = 0; i < num_hungry; i++) {
            int p = hungry[i];
            if (st[p] == 1) {
                printf("Philosopher %d is waiting\n", p + 1);
            }
        }

        for (int i = 0; i < num_hungry; i++) {
            int p = hungry[i];
            if (st[p] == 1 && can_eat(st, p)) {
                wait();
                printf("\nPhilosopher %d is granted to eat\n", p + 1);
                st[p] = 2;
                printf("Philosopher %d has finished eating\n", p + 1);
                st[p] = 0;
                signal();
                eaten++;
            }
        }
    }
}

void two_at_a_time(int st[]) {
    int eaten = 0;

    while (eaten < num_hungry) {
        int granted = 0;

        for (int i = 0; i < num_hungry && granted < 2; i++) {
            int p = hungry[i];
            if (st[p] == 1 && can_eat(st, p)) {
                wait();
                printf("\nPhilosopher %d is granted to eat\n", p + 1);
                st[p] = 2;
                printf("Philosopher %d has finished eating\n", p + 1);
                st[p] = 0;
                signal();
                granted++;
                eaten++;
            }
        }

        for (int i = 0; i < num_hungry; i++) {
            int p = hungry[i];
            if (st[p] == 1) {
                printf("Philosopher %d is waiting\n", p + 1);
            }
        }

        if (granted == 0) {
            printf("No philosophers could eat in this round. Retrying...\n");
        }
    }
}

int main() {
    int choice;

    printf("Enter total number of philosophers: ");
    scanf("%d", &total);

    printf("How many philosophers are hungry? ");
    scanf("%d", &num_hungry);

    for (int i = 0; i < total; i++) {
        state[i] = 0;
    }

    for (int i = 0; i < num_hungry; i++) {
        printf("Enter hungry philosopher %d position (1 to %d): ", i + 1, total);
        scanf("%d", &hungry[i]);
        hungry[i]--;
        state[hungry[i]] = 1;
    }

    do {
        printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        int local_state[MAX];
        for (int i = 0; i < total; i++) {
            local_state[i] = state[i];
        }

        switch (choice) {
            case 1:
                one_at_a_time(local_state);
                break;
            case 2:
                two_at_a_time(local_state);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
