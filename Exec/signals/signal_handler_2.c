

#include "../../minishell.h"

void	signal_handler_two(int sig_v)
{
	if (sig_v == SIGKILL)
	{
		write(1, "\n", 1);
		// signal(SIGINT, signal_handler_two);
	}
}
