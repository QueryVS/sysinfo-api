#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_METHOD_LEN 8
#define MAX_URI_LEN 128
#define MAX_HTTP_VERSION_LEN 16


typedef struct {
    char* method;
    char* uri;
    char* http_version;
} HttpRequest;

typedef struct {
    int status_code;
    char* content;
} HttpResponse;

void parse_request(const char *raw_request, HttpRequest *request);
void build_response(const HttpResponse *response, char *raw_response);
void free_request(HttpRequest *request);

#endif
