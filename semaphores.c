#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 6, s = 0;
void wait()
{
   --mutex;
}
void signal()
{
    ++mutex;
}


void producer()
{
    wait();
    ++full;

    --empty;

    s++;
    printf("\nProducer produces item %d",s);
    signal();
}


void consumer()
{

   wait();


    --full;


    ++empty;
    printf("\nConsumer consumes item %d",s);
    s                      --;


   signal();
}


int main()
{
    int n, i;
    printf("\n Enter 1 for Producer"
           "\n Enter 2 for Consumer"
           "\n Enter 3 for Exit");


    for (i = 1; i > 0; i++) {

        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch (n) {
        case 1:

            if ((mutex == 1)
                && (empty != 0)) {
                producer();
            }

            else {
                printf("Buffer is full!");
            }
            break;

        case 2:
            if ((mutex == 1)
                && (full != 0)) {
                consumer();
            }

            else {
                printf("Buffer is empty!");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
