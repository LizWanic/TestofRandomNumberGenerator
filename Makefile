# 
# Makefile for test.c CS 3040 Lab6
#

all: testsmall testbig  

testsmall:
	gcc -Wall -g test.c -o testsmall

testbig:
	gcc -Wall -static -g test.c -o testbig

dist:
	tar -cvzf dist6.tgz Makefile test.c results.txt
