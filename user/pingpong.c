#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, int *argv[]){
    int p[2];
    
    pipe(p);
    if(fork() == 0){  //child
    	int buf[1];
    	while(read(p[0], buf, 1) == 0){
    	    //spinlock
    	} 
    	printf("%d: received ping\n", getpid());
    	write(p[1], "b", 1);
    	close(p[0]);
    	close(p[1]);
    	exit(0);
    }
    else{             //parent
        int buf[1];
    	close(0);
    	write(p[1], "a", 1);
    	while(read(p[0], buf, 1) == 0){
    	    //spinlock
    	} 
    	printf("%d: received pong\n", getpid());
    	close(p[0]);
    	close(p[1]);
    	exit(0);
    }
    exit(0);
}
