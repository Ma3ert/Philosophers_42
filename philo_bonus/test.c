#include "philosopher.h"

long long	get_time()
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((long long)(now.tv_usec / 1000) + (now.tv_sec * 1000));
}

void	*ft_test(void *sema)
{
	printf("the child will exit\n");
	exit(EXIT_SUCCESS);
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
	pthread_t pid;
	sem_t *sem;
	int	status;
	pid_t pids[5];
	int i;

	status = 1;
	sem_unlink("sem");
	sem = sem_open("sem", O_CREAT, 0644, 1);
	// pids[0] = fork();
	// if (pids[0] == 0)
	// 	ft_test(sem);
	pthread_create(&pid, NULL, ft_test, (void *)sem);
	pthread_detach(pid);
	sleep(4);
	// pthread_detach(pid);	
	// pid = waitpid(-1, &status, 0);
	// ft_waitpid(pid, status);
	// exit(EXIT_SUCCESS);
}