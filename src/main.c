#include <stdio.h>
#include "server.h"

int main() {
    printf("API Gateway Server Starting...\n");
    while(1) {
        start_server();
        printf("transaction completed, waiting again\n");
    }
    return 0;
}
