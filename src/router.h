#ifndef ROUTER_H
#define ROUTER_H

#include "http_parser.h"
#include "system_info.h"

void route_request(const HttpRequest *request, HttpResponse *response);

#endif
