#ifndef ROUTER_H
#define ROUTER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "http_parser.h"
#include "system_info.h"


void route_request(const HttpRequest *request, HttpResponse *response);

#endif
