#include "minitalk.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putnbr_fd((nbr % 10), fd);
	}
	else
		ft_putchar_fd((nbr + '0'), fd);
}

static void	sig_handler(int	signum, siginfo_t *info, void *context)
{
	static int	bits;
	static char	i;
	(void)context;

	if (signum == SIGUSR1)
		i |= (1 << bits);
	bits++;

	if (bits == 8)
	{
		//printf("%c", i);
		write(STDOUT_FILENO, &i, 1);
		bits = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	handle_exit(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n[SIGINT Received] Shutting down\n", 33);
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;
	struct sigaction	sa_exit;
	(void)argv;

	if (argc != 1)
	{
		write(STDERR_FILENO, "Usage: ./server\n", 16);
		return (1);
	}

	pid = getpid();
	write(STDOUT_FILENO, "Server PID: ", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);

	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = sig_handler;

	sa_exit.sa_handler = handle_exit;
	sigemptyset(&sa_exit.sa_mask);
	sa_exit.sa_flags = 0;
	sigaction(SIGINT, &sa_exit, NULL);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}

//sa.sa_handler -> Assign handler function
// sigemptyset -> No signal blocking
// sa.sa_flags = 0 -> Default behavior