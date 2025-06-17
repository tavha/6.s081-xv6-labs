#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"

int main(int argc, char* argv[]){
    char buf[512];
    char *addi[MAXARG];
    int n;
    int pand = 0;
    
    //inst.
    addi[pand] = malloc(512);
    memcpy(addi[pand], argv[pand], sizeof(argv[pand]));
    pand++;
    
    //right of pipe
    for(pand = 2; pand < argc; pand++){
        addi[pand - 1] = malloc(512);
        memcpy(addi[pand - 1], argv[pand], sizeof(argv[pand]));
    }
    
    
    // left of pipe
    while((n = read(0, buf, sizeof(buf))) > 0){
        addi[pand - 1] = malloc(512);
        memcpy(addi[pand - 1], buf, n);
        
        if(addi[pand - 1][n - 1] == '\n')
            addi[pand - 1][n - 1] = '\0';
        else
            addi[pand - 1][n] = '\0';
        pand++;
        memset(buf, 0, 512);
    }
    
    addi[pand - 1] = 0;
    exec(argv[1], addi);
    
    exit(0);
}
