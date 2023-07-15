
#include <stdio.h>
#include <stdlib.h>

#include "voteCount.h"
#define MAX 256

// count the votes
//
void countVotes( FILE *voteFile, int voted[8] ) {

    // TODO: code to count votes here
    int total = 0;
    // int count = 0;
    int voter_id, vote;
    int spoiled = 0;
    int duplicate = 0;
    int cand_votes[4] = {0};

    // define buffer
    char buffer[MAX];

    // read using fgets
    char read_file = fgets(buffer, sizeof(buffer), voteFile);
    
    while (read_file != NULL) {
        sscanf(buffer, "%d %d", &voter_id, &vote);
        total++;

        if (voter_id > 1999 || voter_id < 1000 || vote < 1 || vote > 3) {
            spoiled++;
            continue;
        }

        int is_duplicate = 0;
        for (int i = 0; i < cand_votes[vote]; i++) {
            if (voted[i] == voter_id) {
                is_duplicate = 1;
                break;
            }
        }

        if (is_duplicate) {
            duplicate++;
            continue;
        }
    
        cand_votes[vote]++;
        voted[vote]++;  // increment for the candidates
        voted[4]++; // calculate total legal vote
    }

    voted[0] = total;
    voted[5] = duplicate + spoiled;
    voted[6] = spoiled;
    voted[7] = duplicate;
 
    return;
}


// print report of the voting
//
void printResults( int voted[8] ) {
    int i;

    // write report to file
    FILE *fp = fopen("report.txt","w");
    printf("\nReport:\n");    
    printf(" %d votes\n",voted[0]);
    printf(" %d legal votes\n",voted[4]);
    printf(" %d illegal votes\n",voted[5]);
    printf("    %d spoiled\n",voted[6]);
    printf("    %d duplicates\n",voted[7]);
    fclose(fp);

    // write results to screen
    printf("\nResults:\n");    
    for( i=1; i<4; ++i )
        printf(" %d votes for candidate %d\n",voted[i],i);

    return;
}

