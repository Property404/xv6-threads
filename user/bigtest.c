#include "types.h"
#include "user.h"
int main(int argc, char** argv){int p;

            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":stack\n"),exec(".stack", argv), printf(2, "Supertest exec %s failed\n", "stack"), exit();
            else
                wait();
        
            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":join\n"),exec(".join", argv), printf(2, "Supertest exec %s failed\n", "join"), exit();
            else
                wait();
        
            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":clone\n"),exec(".clone", argv), printf(2, "Supertest exec %s failed\n", "clone"), exit();
            else
                wait();
        
            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":clone2\n"),exec(".clone2", argv), printf(2, "Supertest exec %s failed\n", "clone2"), exit();
            else
                wait();
        
            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":badclone\n"),exec(".badclone", argv), printf(2, "Supertest exec %s failed\n", "badclone"), exit();
            else
                wait();
        
            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":local\n"),exec(".local", argv), printf(2, "Supertest exec %s failed\n", "local"), exit();
            else
                wait();
        
            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":clone3\n"),exec(".clone3", argv), printf(2, "Supertest exec %s failed\n", "clone3"), exit();
            else
                wait();
        exit();}