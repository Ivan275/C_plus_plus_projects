#!/usr/bin/env python
import subprocess

passed = 0

n_tests = 4;

# Run a for loop of tests.
# Yes, we could ls to get a set of .in files
for i in range(1,n_tests+1):
    print "Running test " + str(i) + "... "
    # Run ./atm_sim < i.in > /dev/null
    # Runs atm_sim with input from i.in and sends output to the garbage.
    rt = str(subprocess.call("./atm_sim < " + str(i) + ".in > /dev/null",shell=True))
    # Compare rt to the ground truth.
    f = open (str(i) + ".gt",'r')
    gt = f.read();

    if rt.strip() == gt.strip():
        passed += 1
        print "passed"
    else:
        print "failed"




print "Passed " + str(passed) + " of " + str(n_tests) + " tests"
