#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *buffer ="hihi";
    char filepath[256];
    strcpy(filepath, "/home/lap10547/Documents/");
    char *x=  (char *)calloc(sizeof(char *)*5);
    strcpy(x, filepath);
    printf("%s",*x);
    printf("filepath received from client: %s\n", buffer);
}