#!/usr/bin/env python3
# Make a "super" test that runs all tests
import os
from shutil import copyfile

def create_big_test():
    # initial source for the makefile
    makefile = "USER_PROGS := $(USER_PROGS)"

    # initial source for the actual big ol' test
    source = """#include "types.h"
#include "user.h"
int main(int argc, char** argv){int p;
"""
    for root, d, files in os.walk("../user/tests/"):
        for f in files:
            copyfile(root+f, "../user/."+f);
            object_name = f.replace(".c","")
            source += f"""
            p = fork();
            if(p<0)
                printf(2, "Supertest fork failed"), exit();
            else if(p==0)
                printf(1, ":{object_name}\\n"),exec(".{object_name}", argv), printf(2, "Supertest exec %s failed\\n", "{object_name}"), exit();
            else
                wait();
        """
            makefile+=f"\\\n\t.{object_name}"
        break
    source += "exit();}"
    with open("../user/bigtest.c", "w") as f:
        f.write(source);
    with open("../user/unitmake.mk", "w") as f:
        f.write(makefile);

if __name__=="__main__":
    create_big_test();

#TESTS = [];
#with open("../user/makefile.mk", "r") as f:
#    contents = f.read().replace("\\","");
#    contents = contents[contents.find("wc"):contents.find("zombie")]
#    TESTS = contents.split()[1::];
#
#source = """
##include "types.h"
##include "user.h"
#
#int main(int argc, char** argv)
#{
#int p;
#"""
#
#for t in TESTS:
#    source += f"""
#    
#    p = fork();
#    if(p<0)
#        printf(2, "Supertest fork failed"), exit();
#    else if(p==0)
#        printf(1, ":{t}\\n"),exec("{t}", argv), printf(2, "Supertest exec %s failed\\n", "{t}"), exit();
#    else
#        wait();
#"""
#
#source += "exit();}"
#
#with open("../user/supertest.c", "w") as f:
#    f.write(source);
#    """
