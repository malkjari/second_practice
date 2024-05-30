#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "mysyslog.h"

int main(int argc, char *argv[]) {
    int level = INFO;
    int driver = TEXT;
    int format = PLAIN;
    const char *msg = NULL;
    const char *path = "/var/log/mysyslog.log";

    int opt;
    while ((opt = getopt(argc, argv, "m:l:d:f:p:")) != -1) {
        switch (opt) {
            case 'm': msg = optarg; break;
            case 'l': level = atoi(optarg); break;
            case 'd': driver = atoi(optarg); break;
            case 'f': format = atoi(optarg); break;
            case 'p': path = optarg; break;
            default: 
                fprintf(stderr, "Usage: %s -m msg -l level -d driver -f format -p path\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (!msg) {
        fprintf(stderr, "Message is required\n");
        exit(EXIT_FAILURE);
    }

    if (mysyslog(msg, level, driver, format, path) != 0) {
        fprintf(stderr, "Logging failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
