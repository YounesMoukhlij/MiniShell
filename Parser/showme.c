/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:23:26 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/09 16:20:53 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




void show_me (t_minishell *cmp)
{
   t_minishell  *tmp = cmp;
   int i = 0;
	while (tmp)
	{
		i = 0;
		printf("\n");
		printf("---------commad:-----------\n");
		while(tmp->cmdt[i])
		{
			printf("cmdt[%i]:%s\n",i,tmp->cmdt[i]);
			i++;
		}
		printf("---------FILES:-----------\n");
		i = 1;
		if (tmp->files)
		{
			while(tmp->files[i])
		{
			printf("file [%i]: %s\n",i,tmp->files[i]);
			i++;
		}
		}
		else
			printf("file [x]: NULL");
		i = 0;
		printf("---------after command:-----------\n");
			while(tmp->afcmd_t[i])
			{
					printf("afcmd_t [%i]: %s\n",i,tmp->afcmd_t[i]);
				i++;
			}
		printf("---------arr[x] :-----------\n");
		i = 0;
		if (tmp->tab)
		{
			while(i  < tmp->len_tab)
			{
				printf("tab [%i]: %i\n",i,tmp->tab[i]);
				i++;
			}
		}
		printf("len : %d\n",tmp->len_tab);
		printf("\n--------------------\n");
		i= 0;
		while(tmp->cmd[i])
			printf("%s\n",tmp->cmd[i++]);
		tmp =  tmp->next;
	}
}
