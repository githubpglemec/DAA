#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

int jobSequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(jobs[0]), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        schedule[i] = -1;
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;
        while (deadline > 0 && schedule[deadline - 1] != -1) {
            deadline = deadline - 1;
        }

        if (deadline > 0) {
            schedule[deadline - 1] = i;
            totalProfit = totalProfit + jobs[i].profit;
        }
    }

    return totalProfit;
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for job %d:\n", i + 1);
        printf("Job ID: ");
        scanf(" %c", &jobs[i].id);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }

    int totalProfit = jobSequencing(jobs, n);

    printf("Total profit: %d\n", totalProfit);

    return 0;
}
