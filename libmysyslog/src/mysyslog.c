#include "mysyslog.h"
#include <stdio.h>
#include <time.h>

extern int log_to_text(const char* msg, int level, const char* path);
extern int log_to_json(const char* msg, int level, const char* path);

int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    switch(driver) {
        case TEXT:
            return log_to_text(msg, level, path);
        case JSON:
            return log_to_json(msg, level, path);
        default:
            return -1;
    }
}

const char* log_level_str(int level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARN: return "WARN";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

