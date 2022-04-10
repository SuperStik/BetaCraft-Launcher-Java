#include "Core.h"
#include "Logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

void CreateFileStructure()
{
    char bcdir[500];
    char path[500];

	#if __APPLE__
        strcpy(bcdir, getenv("HOME"));
        strcat(bcdir, "/Library/Application Support/.betacraft/");
	#elif _WIN32
	    strcpy(bcdir, getenv("APPDATA"));
        strcat(bcdir, "\\.betacraft\\");
	#elif __LINUX__
        strcpy(bcdir, getenv("HOME"));
        strcat(bcdir, "/.betacraft/");
    #else
        logger("Error", "This operating system is not supported")
    #endif

    //Create directories
    mkdir(bcdir, 0777);

    for (int i = 0; i<sizeof(directories_array) / sizeof(directories_array[0]); i++)
    {
        strcpy(path, bcdir);
        strcat(path, directories_array[i]);
        mkdir(path, 0777);
    }

    FILE* bcsettings;
    strcpy(path, bcdir);
    strcat(path, "launcher/launcher.settings");
    bcsettings = fopen(path, "rb+");

    //If the file doesn't exist, create one
    if (bcsettings == NULL)
    {
        bcsettings = fopen(path, "wb");

        if (bcsettings == NULL)
        {
            logger("Error", "Couldn't create launcher.settings");
        }
    }

    fclose(bcsettings);
}

int main() {
    CreateFolderStructure();

    return 0;
}