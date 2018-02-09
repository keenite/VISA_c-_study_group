#include <iostream>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

/*************************************
* struct sockaddr {
*         unsigned short sa_family; // address family, AF_xxx
*             char sa_data[14]; // 14 bytes of protocol address
* };
*
* struct sockaddr_in {
*         short int sin_family; // Address family, AF_INET
*             unsigned short int sin_port; // Port number
*                 struct in_addr sin_addr; // Internet address
*                     unsigned char sin_zero[8]; // Same size as struct sockaddr
* };
*
* struct in_addr {
*         unsigned long s_addr;  // load with inet_aton()
* };
*
* The sockaddr_in and sockaddr have the same size, we can freely cast from on to another
**************************************/

int main()
{
    struct sockaddr_int myaddr;
    int s;

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(3490);

    inet_aton("63.161.169.137", &myaddr.sin_addr.s_addr);

    return 0;
}
