//
/* (C) 2024 Author QueryVS
 * read proc file metric and write buffer
 * 
 */

#include "system_info.h"

static char* file_read(const char* file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        char *error = malloc(30);
        if (error) {
            strcpy(error, "Don't read metric file.");
        }
        return error;
    }

    char *buffer = NULL;
    size_t buffer_size = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        size_t line_length = strlen(line);
        char *new_buffer = realloc(buffer, buffer_size + line_length + 1);
        if (new_buffer == NULL) {
            free(buffer);
            fclose(file);
            return NULL;
        }
        buffer = new_buffer;
        memcpy(buffer + buffer_size, line, line_length + 1);
        buffer_size += line_length;
    }

    fclose(file);
    return buffer;
}

char* get_cpu_info() {
    return file_read("/proc/cpuinfo");
}
char* get_mem_info() {
    return file_read("/proc/meminfo");
}
char* get_disk_info() {
    return file_read("/proc/diskstats");
}

