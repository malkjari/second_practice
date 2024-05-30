#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mysyslog.h"

volatile sig_atomic_t stop = 0;

void handle_signal(int sig) {
    if (sig == SIGTERM || sig == SIGINT) {
        stop = 1;
    }
}

void daemonize() {
    pid_t pid, sid;
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

void read_config(const char* config_file, char* path, int* driver, int* format) {
    FILE* file = fopen(config_file, "r");
    if (file) {
        fscanf(file, "path=%s\n", path);
        fscanf(file, "driver=%d\n", driver);
        fscanf(file, "format=%d\n", format);
        fclose(file);
    }
}

int main() {
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    daemonize();

    char path[256] = "/var/log/mysyslog.log";
    int driver = TEXT;
    int format = PLAIN;

    read_config("/etc/mysyslog/mysyslog.cfg", path, &driver, &format);

    while (!stop) {
        mysyslog("Daemon message", INFO, driver, format, path);
        sleep(5);
    }

    mysyslog("Daemon stopping", INFO, driver, format, path);
    return 0;
}
