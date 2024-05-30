#include "mysyslog.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int log_to_json(const char* msg, int level, const char* path) {
    FILE* file = fopen(path, "a");
    if (!file) return -1;

    time_t now = time(NULL);
    fprintf(file, "{\"timestamp\":%ld,\"log_level\":\"%s\",\"process\":\"example-app\",\"message\":\"%s\"}\n", 
            now, log_level_str(level), msg);
    fclose(file);

    return 0;
}
