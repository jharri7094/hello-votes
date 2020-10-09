CC = gcc

CFLAGS = -g -Wall -O0 -std=gnu99


lab5: hellothread.c votecounter.c
	gcc -pthread -o hellothread hellothread.c
	gcc -pthread -o votecounter votecounter.c
 
	
	
	
  
