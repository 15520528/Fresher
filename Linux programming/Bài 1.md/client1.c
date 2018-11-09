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

    // khai báo tên domain mà socket sẽ dung
    address.sin_family = AF_INET;                     
    address.sin_addr.s_addr = inet_addr("127.0.0.1");    //địa chỉ ip server,
    address.sin_port = htons(9734);                   //port sẽ sử dụng để giao tiếp
    len = sizeof(address);

    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1) // nếu thiết lập kết nối thất bại
    {
        perror("oops: client1");
        exit(1);
    }

    char *filename = argv[1]; //lấy tên file mà client muốn down
    ssize_t numBytesRecv = 0;//số lượng byte nhận từ server 
     //gửi kết nối tới server với message là tên file
    send(sockfd, filename, strlen(filename), 0);

    printf("[+] Client's waiting download file %s\n", filename);

    FILE *fp = fopen(filename, "wb");

    do
    {
        numBytesRecv = recv(sockfd, buffer, 256, 0);
        printf("%s\n", buffer);
        if (numBytesRecv == 0)
            break;
        fwrite(buffer, 1, numBytesRecv, fp); // ghi tưngf byte được nhận vào file
        memset(&buffer, 0, sizeof(buffer)); //làm sạch buffer
    } while (numBytesRecv > 0);

    fclose(fp); //đóng file 
    close(sockfd); //đóng kết nối socket
    exit(0);
}
