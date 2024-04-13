

#include "../../minishell.h"

void	signal_handler_two(int sig_v)
{
	if (sig_v == SIGKILL)
	{
		puts("EXITED\n");
		// signal_handler_two(sig_v);
		exit(0);
	}
}
