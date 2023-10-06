#include "minitalk.h"

int main(int ac, char **av)
{
    ft_printf("The PID of this process is: %d\n", getpid());
    while (1)
        usleep(50);
    signal(SIGUSR1, info_client);
	signal(SIGUSR2, info_client);
}