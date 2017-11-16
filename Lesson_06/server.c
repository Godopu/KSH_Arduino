#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 9999

#define MAXLEN 1024
void error_handling(char *message);

int readMessage(int sock , char* message);
void writeMessage(int sock , char* message);
int main(int argc, char *argv[])
{
    int serv_sock;
    int clnt_sock;
    int read_len , idx;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[MAXLEN]="Hello World!";

    serv_sock=socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(PORT);

    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
        error_handling("bind() error");

    if(listen(serv_sock, 5)==-1)
        error_handling("listen() error");

    clnt_addr_size=sizeof(clnt_addr);

    while(1)
    {
        puts("Server] Listening...");
        clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);
        if(clnt_sock==-1)
            error_handling("accept() error");
        puts("Server] Accepted!!");

        while(readMessage(clnt_sock , message)!= -1)
        {
            fputs("receive msg] ", stdout);
            fputs(message , stdout);
            fputs("send msg] ", stdout);
            fputs(message , stdout);
            writeMessage(clnt_sock , message);

            puts("");
        }


        message[0] = 0;
        idx = 0;


    }


    close(serv_sock);
    return 0;
}

int readMessage(int sock , char* message)
{
    int read_len = 0;
    int idx = 0;
    while(read_len=read(sock, &message[idx], 1))
    {
        if(read_len==-1){
            error_handling("read() error!");
            return -1;
        }

        if(message[idx++] == '\n'){
            message[idx] = 0;
            return 0;
        }
    }

    return -1;
}

void writeMessage(int sock , char* message)
{
    write(sock, message, strlen(message));
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}