#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int n = 1;

void *thread()
{
    sleep(1);
    printf("thread-%d running\n" , n);
    return NULL;
}

int main()
{
    for(int i = 0 ; i < 5 ; i++)
    {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread, NULL);
        pthread_join(thread_id, NULL);

        printf("thread-%d closed\n" , n);
        n++;
    }
    return 0;
}