#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, int *argv[]){
    if(argc > 2){
        printf("too many argument.");
    }
    exit(0);
}
