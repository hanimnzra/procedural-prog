
#include <stdio.h>
#include <stdlib.h>

#include "checks.h"
#include "voteCount.h"

// main function
//
// Expected use:   "./voteCount filename"
// where filename is a text file of voting data
//
int main( int argc, char **argv )
{

    // TODO: use the functions in check.c and voteCount.c to complete the vote counting
    
    // check command line arguments with parseArgs() function
    char * filename = parseArgs(argc, argv);

    // open file with openFile() function
    FILE * open = openFile(filename);

    // read in voting data and count votes with countVotes() function
    int voted[8] = {0};
    countVotes(open, voted);

    // print out voting data with printResults() function
    printResults(voted);  

    return 0;
}

