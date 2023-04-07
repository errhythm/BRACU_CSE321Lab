#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int n = 1;

void *thread()
{
    sleep(1);
    return NULL;
}

int main()
{
    int num = 1;
    for(int i = 0 ; i < 5 ; i++)
    {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread, NULL);
        for (int j = 0; j < 5; j++) {
            printf("Thread %d prints %d\n" , n, num);
            num++;
        }
        pthread_join(thread_id, NULL);

        n++;
    }
    return 0;
}