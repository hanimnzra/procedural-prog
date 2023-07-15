
#include <stdio.h>
#include <stdlib.h>

#include "checks.h"

// check command line arguments
//
char *parseArgs( int count, char **args ) {
    char *textFile;

    // TODO: code to check command line data (use error message below)
    if (count < 2) {
        printf("No input text file specified\nExiting\n"); 
        exit(-1);
    }

    textFile = args[1];
    
    return textFile;
}

// check input text file
//
FILE *openFile( char *txtFile ) {
    // TODO: code to check file name (use error message below)

    FILE *voteFile;

    // open file for reading
    voteFile = fopen(txtFile, "r");
    if (voteFile == NULL) {
        printf("File not found\nExiting\n");
        exit(-1);
    }
    
    fclose(voteFile);
    return voteFile;
}

