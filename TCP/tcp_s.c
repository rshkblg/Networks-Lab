#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
int main(int args,char *argv[])
{
    int s = socket(AF_INET,SOCK_STREAM,0);
    
    struct sockaddr_in saddr,caddr;
    
    saddr.sin_family=AF_INET;
    saddr.sin_addr.s_addr=htonl(INADDR_ANY);
    saddr.sin_port=htons(1999);
    
    socklen_t slen=sizeof(saddr);
    socklen_t clen=sizeof(caddr);
    
    bind(s,(struct sockaddr*)&saddr,slen);
    
    printf("Server connected\n");
    
    listen(s,1);
    
    
    int a=accept(s,(struct sockaddr*)&caddr,&clen);
    
    printf("Client Connected\n");
    
    while(1)
    {
        char b[1024];
        
        recv(a, b, sizeof(b), 0);
        
        printf("Message is %s",b);
    }
    close(s);
}
