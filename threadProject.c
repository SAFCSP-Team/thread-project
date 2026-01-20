#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  

void *print_message_function(void *ptr) {
    char *message = (char *)ptr;

    printf("%s (running thread id: %lu)\n", message, (unsigned long)pthread_self());

    return NULL;
}

int main() {
    pthread_t t0, t1;   

    char *message1 = "Hello from the new thread 1!";
    char *message2 = "Hello from the new thread 2!";

    int return_value1, return_value2;

    return_value1 = pthread_create(&t0, NULL, print_message_function, (void*)message1);
    return_value2 = pthread_create(&t1, NULL, print_message_function, (void*)message2);

    printf("t0 thread id: %lu\n", (unsigned long)t0);
    printf("t1 thread id: %lu\n", (unsigned long)t1);

    printf("main thread id: %lu\n", (unsigned long)pthread_self());

    sleep(3);

    printf("pthread_create return t0: %d\n", return_value1);
    printf("pthread_create return t1: %d\n", return_value2);

    return 0;
}
