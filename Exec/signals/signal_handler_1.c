
#include "../../minishell.h"

void	signal_handler_one(int sig_v)
{
	if (sig_v == SIGINT)
	{
		write(1, "\n", 1);
		display_prompt_msg();
	}
}
