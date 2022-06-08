#include <unistd.h>

int	main(int argc, char *argv[])
{
	argc++;
	(void)argv;

	write(1, "z\n", 2);
	return (0);
}
