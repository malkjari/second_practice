#ifndef DAEMON_H
#define DAEMON_H

#include "mysyslog.h"

void handle_signal(int sig);
void daemonize();
void read_config(const char* config_file, char* path, int* driver, int* format);

#endif // DAEMON_H
