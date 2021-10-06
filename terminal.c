#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int MAXLINE = 256; 
    int MAXARGS = 48;
    char buffer[MAXLINE];
    char *args[MAXARGS];
    pid_t pid;
    int status, args_num = 0;
    char *aux1, *aux2;

    printf("Este é o terminal do Herbert\n");
    printf("Digite (Ctrl-D) para sair\n");
    while(fgets(buffer, MAXLINE, stdin) != NULL) {
        if(buffer[strlen(buffer) - 1] == '\n'){
            buffer[strlen(buffer) - 1] = 0;
        }
        aux1=strdup(buffer);
        for(int j=0; ;j++,aux1 = NULL){
            aux2=strtok(aux1," ");
            if(aux2==NULL){
                break;
            }
            args[j]=aux2;
            args_num+=1;
        }
        free(aux1);
        args[args_num]=(char *)NULL;
        pid=fork();
        if(pid==0){
            execvp(args[0], &args[0]);
            printf("couldn’t execute: %s", buffer);
            exit(127);
        }
        printf("-->");
    }

    exit(EXIT_SUCCESS);
}