#include<stdio.h>
#include<sys/socket.h>
#include<arp/inet.h>
#include<unistd.h>
#include<string.h>
#define PORT 8000

int main(int argc, char const *argv[]){
  
  int valread,sock=0;
  
  struct sockaddr_in serv_addr;
  
  char *hello="CLIENT: Hello Server";
  
  char buffer[1024]={0};
  
  if((sock=socket(AF_INET,SOCK_STREAM,0))<0){
    printf("\n Socket creation error\n");
    return -1;
  }
  
  serv_addr.sin_family=AF_INET;
  serv_addr.sin_port=htons(PORT);
  
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
    printf("\nInvalid Address|Address not supported\n");
    return -1;
  }
  
  send(sock,hello,strlen(hello),0);
  printf("Message is sent\n");
  
  valread=read(sock,buffer,1024);
  printf("Reading Message from server\n");
  printf("Message is: %s\n",buffer);
  
  close(sock);
  
  return 0;
}
