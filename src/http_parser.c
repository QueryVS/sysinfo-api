//
/* (C) 2024 Author QueryVS
 * 
 * http parser methods
 * 
 */

#include "http_parser.h"

void parse_request(const char *raw_request, HttpRequest *request) {
    // http parser
    request->method = malloc(MAX_METHOD_LEN);
    request->uri = malloc(MAX_URI_LEN);
    request->http_version = malloc(MAX_HTTP_VERSION_LEN);

    sscanf(raw_request, "%s %s %s", request->method, request->uri, request->http_version);
    printf("Method: %s, URI: %s, Version: %s\n", request->method, request->uri, request->http_version);
}

void build_response(const HttpResponse *response, char *raw_response) {
    sprintf(raw_response, "HTTP/1.1 %d OK\n\n%s", response->status_code, response->content);
}

void free_request(HttpRequest *request) {
    free(request->method);
    free(request->uri);
    free(request->http_version);
}
