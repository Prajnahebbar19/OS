#include <stdio.h>

int n, fn;

void print(int a, int f[], int fn) {
    printf("For %d\t", a);
    for (int j = 0; j < fn; j++) {
        printf("%d\t", f[j]);
    }
    printf("\n");
}

void FIFO(int s[], int f[], int n, int fn) {
    int st = 0, e = 0, fault = 0;
    for (int i = 0; i < fn; i++) {
        f[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < fn; j++) {
            if (f[j] == -1) {
                f[j] = s[i];
                e++;
                c++;
                fault++;
                print(s[i], f, fn);
                break;
            }
            if (s[i] == f[j]) {
                c++;
                break;
            }
        }
        if (c != 1) {
            if (st >= fn) {
                st = 0;
            }
            f[st] = s[i];
            fault++;
            print(s[i], f, fn);
            st++;
        }
    }
    printf("The no of page faults in FIFO is %d\n", fault);
}

void Optimal(int s[], int f[], int n, int fn) {
    int fault = 0, m[fn];
    for (int i = 0; i < fn; i++) {
        f[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < fn; j++) {
            if (f[j] == -1) {
                f[j] = s[i];
                c++;
                fault++;
                print(s[i], f, fn);
                break;
            }
            if (s[i] == f[j]) {
                c++;
                break;
            }
        }
        if (c != 1) {
            for (int j = 0; j < fn; j++) {
                m[j] = -1;
                for (int k = i + 1; k < n; k++) {
                    if (f[j] == s[k]) {
                        m[j] = k;
                        break;
                    }
                }
            }
            int max = -1, pos = -1;
            for (int j = 0; j < fn; j++) {
                if (m[j] == -1) {
                    pos = j;
                    break;
                }
                if (m[j] > max) {
                    max = m[j];
                    pos = j;
                }
            }
            f[pos] = s[i];
            fault++;
            print(s[i], f, fn);
        }
    }
    printf("The no of page faults in Optimal is %d\n", fault);
}

void LRU(int s[], int f[], int n, int fn) {
    int fault = 0, t[fn];
    for (int i = 0; i < fn; i++) {
        f[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < fn; j++) {
            if (f[j] == -1) {
                f[j] = s[i];
                t[j] = i;
                c++;
                fault++;
                print(s[i], f, fn);
                break;
            }
            if (s[i] == f[j]) {
                c++;
                t[j] = i;
                break;
            }
        }
        if (c != 1) {
            int min = t[0], pos = 0;
            for (int j = 1; j < fn; j++) {
                if (t[j] < min) {
                    min = t[j];
                    pos = j;
                }
            }
            f[pos] = s[i];
            t[pos] = i;
            fault++;
            print(s[i], f, fn);
        }
    }
    printf("The no of page faults in LRU is %d\n", fault);
}

void main() {
    printf("Enter the length of the string: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &fn);
    int s[n], f[fn];
    printf("Enter the string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    FIFO(s, f, n, fn);
    printf("OPTIMAL\n");
    Optimal(s, f, n, fn);
    printf("LRU\n");
    LRU(s, f, n, fn);
}
