#include "philosopher.h"

long long	get_time()
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((long long)(now.tv_usec / 1000) + (now.tv_sec * 1000));
}

void	ft_test(int n)
{
	if (n != 0)
		sleep(20);
	exit(EXIT_FAILURE);
}

void	ft_waitpid(int pid, int status)
{
	printf("this the process id %d\n", pid);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_SUCCESS)
			printf("success\n");
		else if (WEXITSTATUS(status) == EXIT_FAILURE)
			printf("failure\n");
	}
}

int main()
{
	pid_t pid;
	int	status;
	pid_t pids[5];
	int i;

	i = 0;
	while (i < 2)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("the child simulation begin %d\n", i);
			ft_test(i);
		}
		pids[i] = pid;
		printf("the pid of the child: %d[%d]\n", pids[i], i);
		i++;
	}
	pid = waitpid(-1, &status, 0);
	ft_waitpid(pid, status);
}