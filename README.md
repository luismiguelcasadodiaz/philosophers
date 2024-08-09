# philosophers
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

Additionally you will learn about optimize your code to gain some milisecons.

# Overview
Here are the things you need to know if you want to succeed in this assignment:
• One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.<br>
• The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.<br>
• There are also forks on the table. There are as many forks as philosophers.<br>
• Because serving and eating spaghetti with only one fork is inconvenient, a philosopher takes their right and left forks to eat, one in each hand.<br>
• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The <b>simulation stops</b> when a philosopher dies of starvation.<br>
• Every philosopher needs to eat and should never starve.<br>
• Philosophers don’t speak with each other.<br>
• Philosophers don’t know if another philosopher is about to die.<br>
• No need to say that philosophers should avoid dying!<br>

## Global Rules
<ul>  Global variables are forbidden! </ul><br>
<ul>• Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]</ul>
<ol>◦ number_of_philosophers: The number of philosophers and also the number
of forks.</ol>
<ol>◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.</ol>
<ol>◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.</ol>
<ol>◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.</ol>
<ol>◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.</ol>
<ul>• Each philosopher has a number ranging from 1 to number_of_philosophers.</ul>
<ul>• Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.</ul>

### Allowed functions in the mandatory project

|Library|Function|Description|
|-------|-----|-------------------------------------------------------------------------------------|
|libc.h|memset|Fills the first n bytes of the memory area pointed by s with the constant c.|
|stdio.h|printf||
|libc.h|malloc|Allocates memory|
|libc.h|free|Frees the memory space pointed to by a pointer |
|history.h|write|writes to a file descripto. It is faster than printf.|
|readline.h|usleep|Suspends execution of the calling thread for (at least) some microseconds|
|readline.h|gettimeofday|gives the number of seconds and microseconds since Epoch. I convert into milliseconds for this project.|
|readline.h|pthread_create||
|readline.h|pthread_detach||
|readline.h|pthread_join||
|readline.h|pthread_mutex_init||
|readline.h|pthread_mutex_destroy||
|readline.h|pthread_mutex_lock||
|readline.h|pthread_mutex_unlock||

### Allowed functions in bonus project




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


# Data structure
```c
typedef struct s_p_moni
{
	pthread_mutex_t	**forks;
	pthread_t	**thread_ids;
	int		num_phi;
	int		ttd;
	int		tte;
	int		tts;
	int		num_lunchs;
	long		*sim_init_ms;
	int		*casualty;
	int		mynum;
	pthread_t	mythread_id;
	int		fork_l;
	int		fork_r;

}	t_moni;

/* ************************************************************************** */
/* t_moni_set() helper function to test a CLI argument in the right field      */
/* forks       Holds a pointer to all available mutexes                       */
/* threads_ids Holds a pointer to all available threads identifications        */
/* num_phi     Holds CLI number of philosophers to simulate                   */
/* ttd         Holds CLI time to die since the beginning of the last meal     */
/*             or the beginning of the simulation                             */
/* tte         Holds CLI time to eat                                          */
/* tts         Holds CLI time to sleep                                        */
/* num_lunchs  Holds CLI optional number of times must eat.                   */
/* sim_ini_ms  Holds a pointer to a timestamp for simulation initiation      */
/* casualty    Holds a pointer to a flag reporting if any Philo died          */
/* mynum       Holds the number of this philosopher                           */
/* fork_l      Holds fork number to use with left hand                        */
/* fork_r      Holds fork number to use with right hand                       */
/* ************************************************************************** */

```
Philosophers get numbers from 1 to num_phi that are stored in mynum. Each Philosopher has a fork for the left hand. The left hand's fork has the same number as the philosopher. The right fork is mynum + 1 for all philosophers but philosopher num_phi, whose right-hand fork is the number one.

![image](https://github.com/user-attachments/assets/a5e028c6-1d6a-40bb-8437-4de2c58647ae)

As forks is an array of mutexes, fork[0] is reserved to synchronize screen output. fork[1]..fork[num_phi] are mutexes for forks. fork[num_phi + 1] will sincronize the start. Fork[num_phi + 2] will protect the write/read of the casualty variable.

memory allocation for Forks and thread_ids is done once arg_ok validates command line arguments.

It is worth paying attention to the special case of two philosophers:


![image](https://github.com/user-attachments/assets/443de854-48db-4833-8928-7aaec58e84ec)

They need to collaborate instead of compete for the forks, so they start blocking the fork with the smaller number.

# Sources of information
Programming with POSIX threads. David R. Butenhof (https://www.amazon.es/Programming-Threads-Addison-Wesley-Professional-Computing-ebook/dp/B006QTHCJ6)

# Sanitizer overhead

I compared the performance of ./philo 4 800 200 200 20 of three different executables.
I got this result:

With Sanitize Thread Execution time in ms: 8228
With Sanitize Address Execution time in ms: 8220
Without Sanitize Execution time in ms: 8211



cat /proc/sys/kernel/sched_rr_timeslice_ms 
100
 % cat /proc/sys/kernel/threads-max
61611
 % cat /proc/sys/kernel/sched_rt_period_us 
1000000
luicasad@car1s3 ~/Documents/cursus/circle4/namada_minshell
 % cat /proc/sys/kernel/sched_rt_runtime_us 
950000
/proc/sys/kernel/sched_rt_period_us
This parameter defines the time period, in microseconds, that is considered to be one hundred percent of the processor bandwidth. The default value is 1000000 μs, or 1 second.
/proc/sys/kernel/sched_rt_runtime_us
This parameter defines the time period, in microseconds, that is devoted to running real-time threads. The default value is 950000 μs, or 0.95 seconds.

##gdb usage to debug threds.
It is possible to debug threads.
In my philosopher project all thread wait for a green light (mutex unlock) to start.
I set  defined a breakpoint in my .gdbinit file to stop main program before unlocking the green light.
At this point with ```set scheduler-locking on``` I stop system scheduler.
```info threads``` show me all threads.
``` thread n``` switch me to thread n. 

In this way i execute step by step each thread individually.

## write vs printf
I started this project considering that would be faster using write() to display simple messages

```bash
100 2 is eating
200 1 is thinking
201 2 is sleeping
201 1 has taken a fork
201 1 has taken a fork
201 1 is eating
301 2 is thinking
```
made only of two integers and short string.

With this in mind...
```c
	ms = ft_itoa(make_timestamp(*a->sim_init_ms), &ms_len);
	me = ft_itoa(a->mynum, &me_len);
	write(1, &ms, ms_len);
	write(1, me, me_len);
	write(1, msg, msg_len);
	free(me);
	free(ms);
```
i started the project.

Having problems keeping alive one philosoher while executing ```./philo 5 800 200 200```, i started to scratch my head.
I change such code por a regular printf()

```c
	printf("%ld %d%s\n", make_timestamp(*a->sim_init_ms), a->mynum, msg);
```

ft_itoa allocates memory to free. my ft_itoa is recursive...

the conclusion was that on average printing 100 000 times a simple message with the write version took 515 ms while using printf version took 275 ms.
