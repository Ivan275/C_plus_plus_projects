#!/usr/bin/env python
import subprocess
import tempfile

passed = 0

n_tests = 5;

# Run a for loop of tests.
# Yes, we could ls to get a set of .in files
for i in range(1,n_tests+1):
    print "Running test " + str(i) + "... "

    # Create a temporary file to contain mode output
    tmpfile = tempfile.NamedTemporaryFile();
    
    # Run ./mode tmpfile < i.in > /dev/null
    # Runs mode with input from i.in and sends output to the garbage.
    cmd = "./mode " + tmpfile.name + " < " + str(i) + ".in > /dev/null";
    rt = str(subprocess.call(cmd,shell=True))

    # Compare output to the ground truth.
    cmd = "diff -b " + tmpfile.name + " " + str(i) + ".gt > /dev/null";
    rt = subprocess.call(cmd,shell=True);

    # Delete temporary file
    tmpfile.close();

    if rt == 0:
        passed += 1;
        print "passed";
    else:
        print "failed";




print "Passed " + str(passed) + " of " + str(n_tests) + " tests";
