#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include <stddef.h>

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
