#include "minishell.h"


int main(int ac, char *av[])
{
	int	f1;
	int	f2;
	int	f3;

	f1 = open(av[1], O_RDWR);
	if (f1 == -1)
	{
		printf("error f1\n");
		exit(1);
	}
	f2 = open(av[2], O_RDWR);
	if (f2 == -1)
	{
		printf("error f2\n");
		exit(1);
	}
	dup2(f1, f2);
	write(f2, "123", 3);
	write(f1, "123", 3);
	printf("f1 == [%d] && f2 == [%d]\n", f1, f2);
	f3 = open("file3", O_CREAT | O_RDWR);
	if (f3 == -1)
	{
		printf("error file3\n");


		
		exit(1);
	}
	dup2(f1, f3);
	write(f3, "123", 3);

	printf("good\n");
}

tmp->inf = openx_np	hjdrgjdfbj;