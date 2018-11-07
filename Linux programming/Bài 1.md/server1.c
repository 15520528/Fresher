#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char buffer[256];
    char sendbuffer[1000];
    int b;
    int server_sockfd, client_sockfd; //tạo 2 socket server và client
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;                //kiểu domain cho socket server
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); //địa chỉ Id ? cái này để làm gì?
    server_address.sin_port = htons(9734);              // port mà socket server sẽ kết nối
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len); //bind server socket với địa chỉ server
    listen(server_sockfd, 5);
    FILE *fp;
    if (fp == NULL)
    {
        fprintf(stderr, "file không tồn tại");
        return 1;
    }
    
    while (1)
    {
        
        char ch;
        printf("server waiting\n");
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd,
                               (struct sockaddr *)&client_address, &client_len);
        recv(client_sockfd, buffer, 256, 0);
        char filepath[256] ;
        strcpy(filepath, "/home/lap10547/Documents/");
        strcat (filepath ,buffer);
        printf("filepath received from client: %s-\n", filepath);
        //fp = fopen(filepath, "rb");
        
        char x[256] = "";
        strcpy(x, filepath);
        fp = fopen(x, "rb");
        // -> Or read(client_sockfd, buffer, 256);
        
        while ((b = fread(sendbuffer, 1, sizeof(sendbuffer), fp)) > 0)
        {
            send(client_sockfd, sendbuffer, b, 0);
        }
        fclose(fp);
        close(client_sockfd);
    }
   
}
void sendFile(){

}