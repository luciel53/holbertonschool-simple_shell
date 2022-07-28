#ifndef HEADER
#define HEADER

struct history
{
    char* commande; 
    struct history *next;
} hist;

int execute (char **argv, char **env);
char *checkFile(char *File);
#endif
