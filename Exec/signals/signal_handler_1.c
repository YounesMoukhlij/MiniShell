
#include "../../minishell.h"

void	signal_handler_one(int sig_v)
{
	if (sig_v == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "nasdasdasd", 100);

		// signal(SIGINT, signal_handler_one);
	}
}
