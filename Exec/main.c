/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:10:00 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/31 14:50:59 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    show(void)
{
    system("leaks minishell");
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int main(int ac, char **av, char **env)
{
    (void)       av;
    (void)       ac;
    (void)       env;
    t_minishell *mini = NULL;;
    // t_minishell **head = NULL;
    t_minishell *mini_1 = NULL;

    int i = 0;
    (void) mini_1;
    (void) i;
    if (ac != 1)
        return (1);
    // atexit(show);

    mini = return_data();
    mini->cmd = malloc(sizeof(char *) * 3);
    mini->cmd[0] = ft_calloc(100, 1);
    strcpy(mini->cmd[0], "export");
    mini->cmd[1] = strdup("t=younes");
    mini->cmd[2] = NULL;


    // FILES
    // mini->files = malloc(sizeof(char *) * 4);
    // mini->files[0] = ft_calloc(100, 1);
    // strcpy(mini->files[0], "file1");
    // mini->files[1] = ft_calloc(100, 1);
    // strcpy(mini->files[1], "file2");
    // mini->files[2] = ft_calloc(100, 1);
    // strcpy(mini->files[2], "file3");
    // mini->files[3] = NULL;
    // mini->tab = malloc(sizeof(int) * 3);
    // mini->tab[0] = 1;
    // mini->tab[1] = 1;
    // mini->tab[2] = 3;
    // mini->len_tab = 3;
    mini->envir = full_fill_env(env);
    // puts("\t--**--\033[32mCommands before execution\033[0m--**--");
    // while (mini->cmd[i])
    // {
    //     printf("- > cmd[%i] == %s\n",i , mini->cmd[i]);
    //     i++;
    // }
    // puts("\t\t--**--\033[36mExecution\033[0m--**--");
    full_fill_path(mini);
    expander(mini);
    // check_fd(mini);
    ft_execute(&mini);

    // printf("in  %d    out   %d\n", mini->fd_in, mini->fd_out);

    // ft_env(mini);

    // i = 0;
    // puts("\n\t--**--\033[31mCommands after execution\033[0m--**--");
    // while (mini->cmd[i])
    // {
    //     printf("- > cmd[%i] == %s\n",i , mini->cmd[i]);
    //     i++;
    // }
    // puts("\n\t\t_____[***]_____2 cmd_____[***]_____\n");
    mini_1 = return_data_1();
    mini_1->cmd = malloc(sizeof(char *) * 3);
    mini_1->cmd[0] = ft_calloc(100, 1);
    strcpy(mini_1->cmd[0], "echo");
    mini_1->cmd[1] = ft_calloc(100, 1);
    strcpy(mini_1->cmd[1], "t=$HOME");
    mini_1->cmd[2] = NULL;
    mini_1->envir = mini->envir;
    mini->next = mini_1;
    // // puts("\t--**--\033[32mCommands before execution\033[0m--**--");
    // while (*head)
    // {
    //     i = 0;
    //     while ((*head)->cmd[i])
    //     {
    //         printf("%s\n", (*head)->cmd[i]);
    //         i++;
    //     }
    //     (*head) = (*head)->next;
    // }
    // // i = 0;
    // // while (mini_1->cmd[i])
    // // {
    // //     printf("- > cmd[%i] == %s\n",i , mini_1->cmd[i]);
    // //     i++;
    // // }
    expander(mini_1);
    puts("\n\n\n\n\t--**--\033[31mCommands after execution\033[0m--**--\n\n\n\n");
    ft_execute(&mini_1);
    // i = 0;
    // while (mini_1->cmd[i])
    // {
    //     printf("- > cmd[%i] == %s\n",i , mini_1->cmd[i]);
    //     i++;
    // }
    // ft_env(mini_1);
    // t_minishell *mini_2;
    // puts("\n\n\n__________3 cmd__________\n\n\n");
    // mini_2 = return_data_2();
    // mini_2->envir = mini_1->envir;
    // ft_execute(mini_2);
    // puts("\n\n\n");
    // ft_env(mini_2);
    // // check_fd(mini);
    return (0);
}
