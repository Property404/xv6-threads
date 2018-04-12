#include "types.h"
#include "user.h"
int main(int argc, char** argv){int p;

            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":clone\n"),exec(".clone", argv), printf(2, "Supertest exec %s failed\n", "clone"), exit();
            else
                wait();
        exit();}