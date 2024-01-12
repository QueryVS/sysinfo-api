#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "router.h"

void route_request(const HttpRequest *request, HttpResponse *response) {

    if (strcmp(request->uri, "/help") == 0) {
        response->status_code = 200;
        response->content = "Endpoints : /meminfo , /cpuinfo , /diskinfo ";
    }

    else if (strcmp(request->uri, "/meminfo") == 0) {
        response->status_code = 200;
        response->content = get_mem_info();
    }

    else if (strcmp(request->uri, "/cpuinfo") == 0) {
        response->status_code = 200;
        response->content = get_cpu_info();
    }

    else if (strcmp(request->uri, "/diskinfo") == 0) {
        response->status_code = 200;
        response->content = get_disk_info();
    }

    else if (strcmp(request->uri, "/") == 0) {
        response->status_code = 200;
        response->content = "API Gateway";
    }

    else {
        response->status_code = 404;
        response->content = "Endpoint not found";
    }

}
