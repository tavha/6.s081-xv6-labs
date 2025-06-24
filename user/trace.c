#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"


void functrace(int mask, char *proc, char *argv[]){
     trace(mask);
     if(fork() == 0){
         exec(proc, argv);
     }
     //wait(0);
}

int main(int argc, char *argv[]){
    int mask[22];
    char *argvlev[MAXARG];
    memset(mask, 0, 22);
    uint64 bits = atoi(argv[1]);
    
    int i = 0;
    while(bits > 0){
        mask[i++] = bits % 2;
        bits /= 2;
    }
    
    for(int j = 3; j < argc; j++){
        argvlev[j - 3] = malloc(512);
        strcpy(argvlev[j - 3], argv[j]);
    }
    
    
    for(i = 0; i < 22; i++){
        if(mask[i]){
            functrace(i, argv[2], argvlev);
        }
    }
    exit(0);
}


