
#include "../../minishell.h"

void	signal_handler_one(int sig_v)
{
	if (sig_v == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		// signal(SIGINT, signal_handler_one);
	}
}
