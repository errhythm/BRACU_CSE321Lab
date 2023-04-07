int main() {
    int n;
    int PID;
    PID = getpid();
    printf("Parent process ID: %d\n",PID);
    n = fork();
    if(n == 0){
        PID = getpid();
        printf("Child process ID: %d\n",PID);
        n = fork();
        if(n == 0){
            PID = getpid();
            printf("GrandChild process ID: %d\n",PID);
        }
        else if(n > 0){
            n = fork();
            if(n == 0){
                PID = getpid();
                printf("GrandChild process ID: %d\n",PID);
            }
            if (n <= 0)return 0;
            n = fork();
            if(n == 0){
                PID = getpid();
                printf("GrandChild process ID: %d\n",PID);
            }
        }
    }
    return 0;
}