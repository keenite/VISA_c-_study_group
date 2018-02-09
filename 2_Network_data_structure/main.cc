#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
* arpa/inet.h
* int inet_pton(int af, const char *src, void *dst); IPv4 and IPv6 from text to binary form
* const char *inet_ntop(int af, const void *src, char *dst, socklen_t size); From binary to text
**************************************/

int main()
{
    struct sockaddr_in myaddr;
    int s;
    char *ipaddr_str;
    unsigned char buf[sizeof(struct in6_addr)];
    char str[INET6_ADDRSTRLEN];

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(3490);

    inet_aton("63.161.169.137", &myaddr.sin_addr);
    cout << myaddr.sin_addr.s_addr << "\n";
    inet_ntop(AF_INET, &myaddr.sin_addr.s_addr, str, INET6_ADDRSTRLEN);
    cout << str << "\n";

    return 0;
}
