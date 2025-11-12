//
/* (C) 2024 Author QueryVS
 * create tcp socket, get accept data and read, call parse function, send response 
 * 
 */

#include "server.h"

void start_server() {
    int socket_tcp; // for creating tcp socket
    int http_accept; // accept http data from socket_tcp
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    if ((socket_tcp = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creating failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(socket_tcp, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(socket_tcp, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(socket_tcp, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    if ((http_accept = accept(socket_tcp, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    read(http_accept, buffer, BUFFER_SIZE);
    HttpRequest request;
    HttpResponse response;
    parse_request(buffer, &request);
    route_request(&request, &response);

    char response_buffer[BUFFER_SIZE];
    build_response(&response, response_buffer);

    write(http_accept, response_buffer, strlen(response_buffer));

    free_request(&request);
    close(http_accept);
    close(socket_tcp);
}
