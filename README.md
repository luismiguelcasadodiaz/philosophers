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
|unistd.h|write|writes to a file descripto. It is faster than printf.|
|unistd.h|usleep|Suspends execution of the calling thread for (at least) some microseconds|
|sys/time.h|gettimeofday|gives the number of seconds and microseconds since Epoch. I convert into milliseconds for this project.|
|pthread.h|pthread_create|Starts a new thread in the calling process. Then new thread starts execution invoking the start_routine|
|pthread.h|pthread_detach|function marks the thread identified by thread as detached.  When a detached thread terminates, its resources are automatically released back to the system without the need for another thread to join with the terminated thread.|
|pthread.h|pthread_join|function waits for the thread specified by thread to terminate.  If that thread has already terminated, then pthread_join() returns immediately.  The thread specified by thread must be joinable.|
|pthread.h|pthread_mutex_init||
|pthread.h|pthread_mutex_destroy||
|pthread.h|pthread_mutex_lock||
|pthread.h|pthread_mutex_unlock||



# Data structures

## There is a general data structure

```c
typedef struct s_p_moni
{
	pthread_mutex_t	**forks;
	t_thread		**threads;
	int				num_phi;
	int				ttd;
	int				tte;
	int				tts;
	int				num_lunchs;
	long			sim_init_ms;
	long			*casualty;
	int				allborn;
}	t_moni;

/* ************************************************************************** */
/* t_moni_set() helper funcion to test a CLI argument in the right field      */
/* forks       Holds a pointer to all available mutexes                       */
/* threads     Holds a pointer to all available threads identificators        */
/* num_phi     Holds CLI number of philosophers to simulate                   */
/* ttd         Holds CLI time to die since the beginning of the last meal     */
/*             or the beginning of the simulation                             */
/* tte         Holds CLI time to eat                                          */
/* tts         Holds CLI time to sleep                                        */
/* num_lunchs  Holds CLI optional number of times must eat.                   */
/* sim_ini_ms  Holds a pointer to a time stamp for simulation initiation      */
/* casualty    Holds a pointer to a flag reporting if any philo died          */
/* allborn     Holds a pointer to a flag reporting if all num_phi were born   */
/* ************************************************************************** */


```

## There is a data structure for each individual thread representing a philosoper.
```c
typedef struct s_thread
{
	pthread_mutex_t	**forks;
	long			*casualty;
	int				allborn;
	long			sim_init_ms;
	pthread_t		thread_id;
	int				num_phi;
	int				ttd;
	int				tte;
	int				tts;
	int				num_lunchs;
	int				my_lunchs;
	int				eating;
	int				mynum;
	int				fork_l;
	int				fork_r;
	long			*s_eat_ms;
	pthread_mutex_t	*s_eat_mtx;
}	t_thread;


/* ************************************************************************** */
/* forks       Holds a pointer to all available mutexes                       */
/* casualty    Holds a pointer to a flag reporting if any philo died          */
/* allborn     Holds a pointer to a flag reporting if all num_phi were born   */
/* sim_ini_ms  Holds a pointer to a time stamp for simulation initiation      */
/* thread_id   Holds the thread identificator                                 */
/* num_phi     Holds CLI number of philosophers to simulate                   */
/* ttd         Holds CLI time to die since the beginning of the last meal     */
/*             or the beginning of the simulation                             */
/* tte         Holds CLI time to eat                                          */
/* tts         Holds CLI time to sleep                                        */
/* num_lunchs  Holds CLI optional number of times must eat.                   */
/* my_lunchs   Holds number of lunch eaten by this philosoper                 */
/* eating      Flag indicating the philosoper is eating now (not used)        */
/* mynum       Holds the number of this philosopher                           */
/* fork_l      Holds fork number to use with left hand                        */
/* fork_r      Holds fork number to use with right hand                       */
/* s_eat_ms    Holds last time this philosoher started to eat                 */
/* s_eat_mtx   THis muttex prevents data races for this previous information  */
/* ************************************************************************** */
```
Philosophers get numbers from 1 to num_phi that are stored in mynum. Each Philosopher has a fork for the left hand. The left hand's fork has the same number as the philosopher. The right fork is mynum + 1 for all philosophers but philosopher num_phi, whose right-hand fork is the number one.

![image](https://github.com/user-attachments/assets/a5e028c6-1d6a-40bb-8437-4de2c58647ae)

As forks is an array of mutexes, fork[0] is reserved to synchronize screen output. fork[1]..fork[num_phi] are mutexes for forks. fork[num_phi + 1]  will protect the write/read of the casualty variable.

memory allocation for Forks and thread_ids is done once arg_ok validates command line arguments.

It is worth paying attention to the special case of two philosophers:


![image](https://github.com/user-attachments/assets/443de854-48db-4833-8928-7aaec58e84ec)

They need to collaborate instead of compete for the forks, so they start blocking the fork with the smaller number. That translated in a rule such as the odd philosopers tries to lock the left hand fork and even philosopher tries to lock the right hand fork.


# usleep vs my_usleep.

Despite it is clearly stated in ``` man usleep ```, a out of the blue, thanks to a 42 mate, i became aware of the word *at least* related with the functionality of such function.

I created a naive device to measure the *accuracy* of usleep() in microseconds and compare it with the one of my_usleep()

```c  
long	my_now_ms(void)
{
	struct timeval	s;
	long			ms;

	gettimeofday(&s, NULL);
	ms = (s.tv_sec * 1000) + (s.tv_usec / 1000);
	return (ms);
}

void	my_usleep(int time)
{
	long	now0_ms;

	now0_ms = my_now_ms();
	while ((my_now_ms() - now0_ms) < time)
		usleep(100);
		//usleep(250);
		//usleep(500);
}
int	main(void)
{
	struct timeval		s;
	struct timeval		e;
	int			i;
	long			e_usec;

	i = 0;
	while (++i <= 200)
	{
		gettimeofday(&s, NULL);
		my_usleep(1000);
        //usleep(1000)
		gettimeofday(&e, NULL);
		e_usec = (e.tv_sec - s.tv_sec) * 1000000 + (e.tv_usec - s.tv_usec);
		printf("%ld\n", e_usec);
	}
	return (0);
}
```

I got the evidence of more accuracy wiht my_usleep() than with usleep().


# Sources of information
Programming with POSIX threads. David R. Butenhof (https://www.amazon.es/Programming-Threads-Addison-Wesley-Professional-Computing-ebook/dp/B006QTHCJ6)

# Sanitizer overhead

I compared the performance of ./philo 4 800 200 200 20 with three different executables.
I got this result:

With Sanitize Thread Execution time in ms: 8228.

With Sanitize Address Execution time in ms: 8220.

Without Sanitize Execution time in ms: 8211.

I concluded that Sanitize adds some overhead, but it was not really impacting my philo proyect performance


## gdb usage to debug threds.
It is possible to debug threads.
In my philosopher project all thread wait for a green light (mutex unlock) to start.
I defined a breakpoint in my .gdbinit file to stop main program before unlocking the green light.

At this point with ```set scheduler-locking on``` I stop system scheduler.

```info threads``` show me all threads.

![imagen](https://github.com/user-attachments/assets/f9c11dbc-4a34-4d20-a4cf-0d49a297a9d2)


``` thread n``` switch me to thread n. 

![imagen](https://github.com/user-attachments/assets/527bf7e6-8653-4e83-9250-84a68990f350)


In this way i execute step by step each thread individually.

## write vs printf
I started this project considering that would be faster using write() to display simple messages made only of two integers and short string.

```bash
100 2 is eating
200 1 is thinking
201 2 is sleeping
201 1 has taken a fork
201 1 has taken a fork
201 1 is eating
301 2 is thinking
```


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

The conclusion was that on average printing 100 000 times a simple message with the write version took 515 ms while using printf version took 275 ms.

## Other considerations

You can check some curent parameters form kernel scheduler.

```bash
cat /proc/sys/kernel/sched_rr_timeslice_ms 
100
 % cat /proc/sys/kernel/threads-max
61611
 % cat /proc/sys/kernel/sched_rt_period_us 
1000000
 % cat /proc/sys/kernel/sched_rt_runtime_us 
950000
```
/proc/sys/kernel/sched_rt_period_us
This parameter defines the time period, in microseconds, that is considered to be one hundred percent of the processor bandwidth. The default value is 1000000 μs, or 1 second.

/proc/sys/kernel/sched_rt_runtime_us
This parameter defines the time period, in microseconds, that is devoted to running real-time threads. The default value is 950000 μs, or 0.95 seconds.
```
