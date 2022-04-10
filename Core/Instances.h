#ifndef INSTANCES_H
#define INSTANCES_H

#include <stdbool.h>

typedef struct
{
    char name[200];
    char launch_args[200];
    char version[200];
    int width;
    int height;
    bool proxy;
    bool keep_open;
    bool RPC;
    char *addons[200];
    char game_directory[200];
} Instance;

#endif