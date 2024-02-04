/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:04:09 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/04 15:31:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    int pipe1[2];
    int pipe2[2];
    int id1;
    int id2;

    if  (pipe(pipe1) == -1|| pipe(pipe2) == -1)
    {
        perror("pipe");
        return(1);
    }

    write(pipe1[1],"hello",strlen("hello"));
    
    id1 = fork();
    if (id1 == 0)
    {
        char buffer[1024];
        close(pipe1[1]);
        close(pipe2[0]);
        
        read(pipe1[0],buffer,1024);
        printf("PID: |%d| |---------->in child<------|%s\n",getpid(),buffer);
        write(pipe2[1],buffer,1024);
    }
    else
    {
        waitpid(-1 , NULL, 0);
        char buffer[1024];
        
        close(pipe1[1]);
        close(pipe2[1]);
        close(pipe1[0]);
        read(pipe2[0],buffer,1024);
        printf("PID: |%d| |---------->in main<------|\n", getpid());
    }
    printf("form PID: %d\n",getpid());
}