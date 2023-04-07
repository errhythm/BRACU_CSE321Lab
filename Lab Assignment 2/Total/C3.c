#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *countASCII(void *input1)
{
    char *input = (char *)input1;

    int output = 0;
    int *result = malloc(sizeof(int));

    int i = 0;
    while (input[i] != '\0')
    {
        output += input[i];
        i++;
    }
    *result = output;
    return (void *)result;
}

int main()
{
    pthread_t th_id1, th_id2, th_id3;

    char *user1 = "Rhythm274";
    char *user2 = "Rhythm";
    char *user3 = "Rhythm";

    pthread_create(&th_id1, NULL, countASCII, user1);
    int *n1;
    pthread_join(th_id1, (void **)&n1);

    pthread_create(&th_id2, NULL, countASCII, user2);
    int *n2;
    pthread_join(th_id2, (void **)&n2);

    pthread_create(&th_id3, NULL, countASCII, user3);
    int *n3;
    pthread_join(th_id3, (void **)&n3);

    if (*n1 == *n2 && *n1 == *n3){
        printf("Youreka\n");
    }
    else if (*n1 == *n2 || *n1 == *n3 || *n2 == *n3){
        printf("Miracle\n");
    }
    else{
        printf("Hasta la vista\n");
    }

    return 0;
}