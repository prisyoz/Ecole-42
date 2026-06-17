#include "minitalk.h"

volatile sig_atomic_t	g_bit = 0;

static void	client_ack(int signum)
{
	(void)signum;
	g_bit = 1;
}

// Convert message to binary
void	char_to_bits(int server_pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		g_bit = 0;
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		// while (!g_bit)
		// 	usleep(2500);
		int timeout = 0;
		while (!g_bit)
		{
			usleep(2500);
			timeout++;
			if (timeout > 400) // If it waits more than 1 second (400 * 2500us)
			{
				write(2, "Server ghosted us! Hanging...\n", 30);
				break; // break the hang so you can see what happened
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	int					i;
	struct sigaction	sa;
	(void)argv;
	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: ./client <Server PID> Message\n", 37);
		return (1);
	}

	sa.sa_handler = client_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);

	server_pid = atoi(argv[1]);
	if (server_pid <= 0 || kill(server_pid, 0) == -1)
	{
		write(2, "Error: Invalid Server PID\n", 26);
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		char_to_bits(server_pid, argv[2][i]);
		i++;
	}
	write(1, "Server ack\n", 11);
	char_to_bits(server_pid, '\n');
	return (0);
}
