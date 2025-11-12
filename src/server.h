#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "http_parser.h"
#include "router.h"

#define PORT 26171
#define BUFFER_SIZE 8096


void start_server();

#endif
