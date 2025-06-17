#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define WRITE_END 1
#define READ_END  0

void sieve(int);

int main(int argc, int* argv[]){
    int p[2]; 
    pipe(p);
    //close(p[READ_END]);
    for(int i = 2; i <= 35; i++){
        write(p[WRITE_END], &i, sizeof(i));
    }
    
    if(fork() == 0){
        close(p[WRITE_END]);
        sieve(p[READ_END]);
    }
    close(p[WRITE_END]);
    wait(0);
    exit(0);
}

void sieve(int fd){
    
    int n;
    read(fd, &n, sizeof(n));
    printf("prime %d\n", n);
    
    int p[2];
    int num;
    pipe(p);
    while(read(fd, &num, sizeof(num))){
    	if(num % n != 0){
    	    write(p[WRITE_END], &num, sizeof(num));
    	}
    }
    close(p[WRITE_END]);
    if(fork() == 0){
        if(num == 0){
            exit(0);
        }
        //printf("y");
        close(p[WRITE_END]);
        sieve(p[READ_END]); 
    }
    else{
        close(p[READ_END]);
    }
    wait(0);
    exit(0);
}
