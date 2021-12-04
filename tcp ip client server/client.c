#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define SIZE 1000

int main()
{
  int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(9002);
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

  char serverResponse[SIZE];
  recv(socketDescriptor, &serverResponse, sizeof(serverResponse), 0);
  printf("Ther server sent the data : %s", serverResponse);
  close(socketDescriptor);
  return 0;
}
