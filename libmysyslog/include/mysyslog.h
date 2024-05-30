#ifndef MYSYSLOG_H
#define MYSYSLOG_H

enum log_level {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
};

enum log_driver {
    TEXT,
    JSON
};

enum log_format {
    PLAIN,
    JSON_FORMAT
};

int mysyslog(const char* msg, int level, int driver, int format, const char* path);
const char* log_level_str(int level);

#endif // MYSYSLOG_H
