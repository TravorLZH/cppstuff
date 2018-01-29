//
// Created by Travor Liu on 1/28/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(void){
    regex_t rx;
    regmatch_t match;
    size_t len;
    char str[]="abcdefgh";
    char* cursor=str;
    int retcode;    // For discovering errors
    retcode=regcomp(&rx,"[[:alpha:]]\\{2\\}",0);
    if(retcode){
        fprintf(stderr,"Failed to compile regex");
        exit(1);
    }
    while(regexec(&rx,cursor,1,&match,0)==0) {
        len = match.rm_eo - match.rm_so;
        char result[strlen(cursor)+1];
        memcpy(result, cursor, len);
        result[len] = 0;
        printf("match: %s\n", result);
        cursor+=match.rm_eo;
    }
    regfree(&rx);
    return 0;
}
