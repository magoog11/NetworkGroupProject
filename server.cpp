/****************************************************************
** Author:                      Corey McGurgan                 **
** Course:                      CSC325                         **
** Assignment                   Network Group Project          **
** Date Created:                October 2020                   **
** Filename:                    server.cpp                     **
** Program Summary:                                            **
**                                                             **
*****************************************************************/

#include <stdio.h>              // for printf() and scanf()
#include <sys/types.h>          // defines of numerous data types
#include <sys/socket.h>         // defines sockaddr structure
#include <netinet/in.h>         // for sockaddr_in()
#include <stdlib.h>             // for atoi()

using namespace std;            // use the standard namespace

const int defaultPort = 80;

int main(int argc,char *argv[])
{
   int sockfd, port_num; // socket file descriptor and port number
   string host_name; // name of host

//command line paramaters format:
// ./server *host name* *port number(optional)*
  if (argc == 0){ // checks for CLA
    perror("NEEDS COMMAND LINE ARGUEMENTS");
    printf("CLA format:\n./server *host name* *port number(optional)*\n");
    return 0; }
  if (argc > 0) //if there was some arguements in the command line...
    host_name = argv[1]; // gets host's name.
  if (argc > 1) // if a port number was given...
    port_num = atoi(argv[2]); // store it in port_num.
  else // otherwise, use default port number.
    port_num = defaultPort;

  /* Creating a socket...
        sockfd = socket(domain, type, protocol)
  Domain: AF_INET - indicates we will be using IPv4.
     other examples include AF_INET6 for IPv6, AF_UNIX for UNIX sockets, etc.
  Type: SOCK_STREAM indicates we are using TCP protocol.
     other main type is SOCK_DGRAM, which is for UDP.
  Protocol: 0, because 0 is the default for TCP.
  */
  sockfd = socket(AF_INET, SOCK_STREAM, 0)

  return 0; // terminates program.
}
