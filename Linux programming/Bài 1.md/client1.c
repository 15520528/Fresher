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
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char buffer[256];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;                     // khai báo tên domain
    address.sin_addr.s_addr = inet_addr("127.0.0.1"); //local host
    address.sin_port = htons(9734);                //port sẽ sử dụng để giao tiếp
    len = sizeof(address);

    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1)
    {
        perror("oops: client1");
        exit(1);
    }
    /*write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    close(sockfd);*/
    //  send filepth that client wana download
    
    //  receive bytes of file received from server
    /*read(sockfd, buffer, sizeof(buffer));
    printf("data: %s", buffer);*/

    char* filename = argv[1];
    ssize_t numBytesRecv = 0;
    send(sockfd, filename, strlen(filename),0);
    
    printf("[+] Client's waiting download file %s", filename);
   FILE *fp = fopen(filename, "wb");
    do{
        numBytesRecv = recv(sockfd, buffer, 256, 0);
        printf("%s\n", buffer);
        if (numBytesRecv == 0)
            break;
        fwrite(buffer, 1, numBytesRecv,     fp);
        memset(&buffer, 0, sizeof(buffer));
    }
    while(numBytesRecv > 0);
    fclose(fp);
    close(sockfd);
    exit(0);
}
