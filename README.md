# philosophers
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

### Allowed functions in mandatory project

There are 18 allowed functions for Pipex. All of them belong to the set of 51 functions allowed in minishell. I summarize them here. It is work in advance to understand minishell.


|Library|Function|Description|
|-------|-----|-------------------------------------------------------------------------------------|
|libc.h|memset|Fills the first n bytes of the memory area pointed by s with the constant c.|
|stdio.h|printf||
|libc.h|malloc|ch|h
|libc.h|free|ild process created by fork(2). |
|history.h|write||
|readline.h|usleep||
|readline.h|gettimeofday||
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
