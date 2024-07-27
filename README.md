# philosophers
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

# Overview
Here are the things you need to know if you want to succeed this assignment:
• One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.<br>
• The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping;and, of course, while sleeping, they are not eating nor thinking.<br>
• There are also forks on the table. There are as many forks as philosophers.<br>
• Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.<br>
• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The <b>simulation stops</b> when a philosopher dies of starvation.<br>
• Every philosopher needs to eat and should never starve.<br>
• Philosophers don’t speak with each other.<br>
• Philosophers don’t know if another philosopher is about to die.<br>
• No need to say that philosophers should avoid dying!<br>

### Allowed functions in mandatory project

There are 18 allowed functions for Pipex. All of them belong to the set of 51 functions allowed in minishell. I summarize them here. It is work in advance to understand minishell.


|Library|Function|Description|
|-------|-----|-------------------------------------------------------------------------------------|
|libc.h|memset|Fills the first n bytes of the memory area pointed by s with the constant c.|
|stdio.h|printf||
|libc.h|malloc|Allocates memory|
|libc.h|free|Frees the memor space pointed to by a pointer |
|history.h|write|writes to a file descripto. It is faster than printf.|
|readline.h|usleep|Suspends execution of the calling thread for some microseconds|
|readline.h|gettimeofday|gives the number of seconds and microseconds since Epoch. I convert into millisecons for this project.|
|readline.h|pthread_create||
|readline.h|pthread_detach||
|readline.h|pthread_join||
|readline.h|pthread_mutex_init||
|readline.h|pthread_mutex_destroy||
|readline.h|pthread_mutex_lock||
|readline.h|pthread_mutex_unlock||

### Allowed functions in bonus project

There are 18 allowed functions for Pipex. All of them belong to the set of 51 functions allowed in minishell. I summarize them here. It is work in advance to understand minishell.


|Library|Function|Description|
|-------|-----|-------------------------------------------------------------------------------------|
|dirent.h|memset||
|dirent.h|printf||
|dirent.h|malloc||
|fcntl.h|free|The open() system call opens/creates the file specified by pathname in read/write mode if currente permission allow it. I used it with file1 and file2. <br> O_CLOEXEC Enable  the  close‐on‐exec  flag for the new file descriptor. It is essential in some multithreaded programs to avoid race conditions where one thread opens a file descriptor and attempts to set its close‐on‐exec flag using fcntl(2) at the same  time  as  another  thread  does  a fork(2)  plus execve(2).  Depending on the order of execution, the race may lead to the file descriptor returned by open() being unintentionally leaked to the program executed by the child process created by fork(2). |
|history.h|write||
|history.h|fork||
|history.h|kill||
|history.h|exit||
|history.h|waitpid||
|readline.h|usleep||
|readline.h|gettimeofday||
|readline.h|pthread_create||
|readline.h|pthread_detach||
|readline.h|pthread_join||
|readline.h|pthread_sem_open||
|readline.h|pthread_sem_close||
|readline.h|pthread_sem_post||
|readline.h|pthread_sem_wait||
|readline.h|pthread_sem_unlink||


# 
