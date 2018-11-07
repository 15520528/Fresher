# README
 socket domain chỉ định network medium mà socket sẽ sử dụng, ví dụ AF_INET
 
 Socket Types
Internet protocols provide two communication mechanisms with distinct levels of service: streams
and datagrams.

loopback network

IPC interprocess communication 

file system socket : các process sẽ giao tiếp với nhau thông qua một file descriptor
network socket: các process sẽ giao tiếp với nhau thông qua mạng với địa chỉ IP và một port xác định

To enable computers of different types to agree on values for multibyte integers transmitted over a net-
work, you need to define a network ordering. Client and server programs must convert their internal
integer representation to the network ordering before transmission. They do this by using functions
defined in netinet/in.h . These are
#include <netinet/in.h>
unsigned
unsigned
unsigned
unsigned
long int htonl(unsigned long int hostlong);
short int htons(unsigned short int hostshort);
long int ntohl(unsigned long int netlong);
short int ntohs(unsigned short int netshort);

fork(): 
> negative :thất bại trong việc tạo process con
   
    0 : một process mới được tạo
    
    positive: returned to parent 

socket blocking là hiện tượng xảy ra khi một socket đang listen các connections, Khi một kết nối được chấp nhận và có lời gọi I/O làm cho các kết nối đến sau phải chời cho tới khi các lời gọi I/O thực hiện xong..