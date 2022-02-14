#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<time.h>
#define PORT 9002
#define BACKLOG 10
int main(){
  time_t currentTime ;
  time(&currentTime);
  int countClient = 0; 
  int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in  serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr=INADDR_ANY;
  serverAddress.sin_port=htons(PORT);
  bind(socket_descriptor,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
  listen(socket_descriptor,BACKLOG);
  printf("\nServer Started ...");
  while(1){
  countClient++;
  printf("\n");
  int client_socket = accept(socket_descriptor, NULL, NULL);
  printf("\nClient %d has requested for time at %s", countClient, ctime(&currentTime));
  send(client_socket,ctime(&currentTime), 30, 0);   
  }
  return 0;
}
