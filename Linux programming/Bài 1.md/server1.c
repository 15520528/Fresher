#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *sendFile(void *);
struct thread_args
{
    char filePath[256];
    int sock;
};

int main()
{
    char buffer[256];
    char filepath[256];
    char sendbuffer[1000];
    int b;
    int server_sockfd, client_sockfd, *new_sock; //tạo 2 socket server và client
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
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
        if (client_sockfd > 0)
        {

            recv(client_sockfd, buffer, 256, 0);
            pthread_t sniffer_thread;
            new_sock = malloc(sizeof *new_sock);
            struct thread_args *thread_data = malloc(sizeof *thread_data);
            strcpy(thread_data->filePath, "/home/lap10547/Documents/");
            strcat(thread_data->filePath, buffer);
            thread_data->sock = client_sockfd;

            if (pthread_create(&sniffer_thread, NULL, sendFile, (void *)thread_data) < 0)
            {
                perror("could not create thread");
                return 1;
            }

            /*
            strcpy(filepath, "/home/lap10547/Documents/");
            strcat(filepath, buffer);
            printf("filepath received from client: %s\n", filepath);
            fp = fopen(filepath, "rb");

            if (fp != NULL)
            {
                while ((b = fread(sendbuffer, 1, sizeof(sendbuffer), fp)) > 0)
                {
                    send(client_sockfd, sendbuffer, b, 0);
                }
            }
            
            close(client_sockfd);*/
            memset(&buffer, 0, sizeof(buffer));
        }
    }
}
void *sendFile(void *client_sockfd)
{
    struct thread_args thread_agr = *(struct thread_args *)client_sockfd;
    printf("slient_sockfd:  %d %s\n", thread_agr.sock, thread_agr.filePath);
    char sendbuffer[1000];
    int b;
    FILE *fp;
    char filepath[256];
    strcpy(filepath, thread_agr.filePath);
    //printf("filepath received from     client: %s\n", filepath);
    fp = fopen(filepath, "rb");
    while ((b = fread(sendbuffer, 1, sizeof(sendbuffer), fp)) > 0)
    {
        send(thread_agr.sock, sendbuffer, b, 0);
    }
    /*
    fclose(fp);
    free(client_sockfd);
    */
    close(thread_agr.sock);
    pthread_exit(NULL);
}