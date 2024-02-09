#include "headers/pipex.h"
int main()
{
    int i = 0;

    i = access(NULL,F_OK);
    printf("%d\n",i);
}