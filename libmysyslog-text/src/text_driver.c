#include "mysyslog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int log_to_text(const char* msg, int level, const char* path) {
    FILE* file = fopen(path, "a");
    if (!file) return -1;

    time_t now = time(NULL);
    fprintf(file, "%ld %s %s %s\n", now, log_level_str(level), "example-app", msg);
    fclose(file);

    return 0;
}
