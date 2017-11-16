#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define IP_ADR "127.0.0.1"
#define PORT 9999

void error_handling(char *message);
void writeMessage(int sock , char* message);
int readMessage(int sock , char* message);

int main(int argc, char* argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];

    sock=socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(IP_ADR);
    serv_addr.sin_port=htons(PORT);

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
        error_handling("connect() error!");

    message[0] = 0;
    while(strcmp(message , "exit") != 0)
    {
        printf("Enter a message : ");
        fgets(message , sizeof(message) , stdin);

        writeMessage(sock , message);
        fputs("send msg] ", stdout);
        fputs(message , stdout);

        fputs("receive msg] ", stdout);
        fputs(message , stdout);
        if(readMessage(sock , message) == -1)
            return 0;

        puts("");
    }
    close(sock);
    return 0;
}

//
void writeMessage(int sock , char* message)
{
    write(sock, message, strlen(message));
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

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}