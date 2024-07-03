#include <stdio.h>

int p, r;

void safety(int p, int r, int all[p][r], int avail[r], int req[p][r], int seq[p]) {
    int f[p], c, count = 0, h = 0;
    for (int i = 0; i < p; i++) {
        f[i] = 0;
    }
    while (count < p && h < p) {
        for (int i = 0; i < p; i++) {
            if (f[i] == 0) {
                c = 0;
                for (int j = 0; j < r; j++) {
                    if (req[i][j] <= avail[j]) {
                        c++;
                    }
                }
                if (c == r) {
                    printf("P%d is visited(",i);
                    for (int k = 0; k < r; k++) {
                        avail[k] += all[i][k];
                        printf("%d",avail[k]);

                    }
                    printf(")\n");
                    f[i] = 1;
                    count++;
                    seq[h] = i;
                    h++;

                }
            }
        }
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    int tot[r], req[p][r], avail[r], seq[p],all[p][r];
    printf("Enter the details of each process (allocation matrix):\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    printf("Enter the request matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &req[i][j]);
        }
    }
    printf("Enter the initial available instances of each resource:");
    for(int i=0;i<r;i++)
    {
        scanf("%d",&avail[i]);
    }
    safety(p, r, all, avail, req, seq);

    printf("Safe sequence is: ");
    for (int i = 0; i < p; i++) {
        printf("P%d\t", seq[i]);
    }
    return 0;
}
