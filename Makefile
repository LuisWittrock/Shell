#!/usr/bin/enb bash

compiling:
	echo "compiling..." 

	g++ -o SHELL SHELL.cpp -lboost_filesystem

	echo "compiling done"

cleaning up:
	echo "cleaning up..."

	rm -f SHELL.o

	echo "cleaning up done"

finished: 
	echo "finished"
	
