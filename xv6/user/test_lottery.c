#include "types.h"
#include "user.h"
#include "pstat.h"

void spin() {
    int i, j, k;
    for (i = 0; i < 50; ++i) {
        for (j = 0; j < 400000; ++j) {
            k = j % 10;
            k = k + 1;
        }
    }
}

void print(struct pstat *pst){
    int j;
        for (j = 0; j < NPROC; j++) {
            if (pst->inuse[j] == 1) {
                printf(1, "pid:%d, tickets:%d, ticks:%d\n", pst->pid[j], pst->tickets[j], pst->ticks[j]);
            }
        }
        printf(1,"\n");
}

int main(int argc, char *argv[]) {
    int tickets[] = {30, 20, 10};
    int pid_chds[3];
    int i;

    for (i = 0; i < 3; i++) {
        pid_chds[i] = fork();
        if (pid_chds[i] == 0) {  
            settickets(tickets[i]);  
            for (;;) {
                spin();
            }
        }
    }

    struct pstat st;

    for(i=10;i<=500;i=i+10) {
        if (getpinfo(&st) != 0) {
            printf(1, "check failed: getpinfo\n");
            goto Cleanup;
        }
        else{
            printf(1, "********PINFO at time %d********\n", i);
            print(&st);
        }
        sleep(10);  // To slow down the process
    }

Cleanup:
    for (i = 0; pid_chds[i] > 0; i++) {
        kill(pid_chds[i]);
    }
    while (wait() > -1);

    exit();
}
