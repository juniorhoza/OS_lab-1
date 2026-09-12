Section II - Build Your Own Library (util)
COP 5614
==========================================

This project builds a small C library called "util" that contains five
functions, and demonstrates linking it three ways: as a STATIC library
(.a), as a SHARED library (.so), and by loading it DYNAMICALLY at run
time with dlopen/dlsym/dlclose.

FILES
-----
  util.h        - declarations for all five library functions
  util_file.c   - util_file()   prints a message
  util_net.c    - util_net()    prints a message
  util_math.c   - util_math()   prints a message
  util_power.c  - util_power(base, power)  returns base^power   (Problem 1)
  gcd.c         - gcd(u, v)      binary GCD                     (Problem 3)
  main1.c       - test program that calls all FIVE functions   (Problems 2 & 4)
  main_dyn.c    - loads libutil.so at run time via dlopen
  Makefile      - builds and runs everything

QUICK START
-----------
  make run       # builds static + shared + dynamic, then runs all three
  make clean     # removes every generated file

BUILDING BY HAND
----------------
1) STATIC library (.a)
     gcc -c util_file.c util_net.c util_math.c util_power.c gcd.c
     ar rc libutil.a util_file.o util_net.o util_math.o util_power.o gcd.o
     ranlib libutil.a
     gcc -c main1.c
     gcc main1.o -L. -lutil -o prog
     ./prog

2) SHARED library (.so)
     gcc -fPIC -c util_file.c util_net.c util_math.c util_power.c gcd.c
     gcc -shared -o libutil.so util_file.o util_net.o util_math.o util_power.o gcd.o
     gcc main1.o -L. -lutil -o prog_shared
     export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
     ./prog_shared

3) DYNAMIC loading (dlopen)
     gcc main_dyn.c -ldl -o prog_dyn
     ./prog_dyn

EXPECTED OUTPUT (prog and prog_shared)
--------------------------------------
  Inside main()
  Inside util_file()
  Inside util_net()
  Inside util_math()
  util_power(2, 10) = 1024
  gcd(48, 36)       = 12

EXPECTED OUTPUT (prog_dyn)
--------------------------
  Loaded libutil.so dynamically:
  Inside util_file()
  util_power(2, 10) = 1024
  gcd(48, 36)       = 12



Tested on Linux / WSL (Ubuntu) with gcc.
