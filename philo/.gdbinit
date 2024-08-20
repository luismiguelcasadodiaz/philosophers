#234567890123456789012345678901234567890123456789012345678901234567890123456789#
#        1         2         3         4         5         6         7         #
#..............................................................................#
# Luis Miguel Casado Díaz (LMCD) .gdbinit configuration file                   #
#                                                                              #
# 2024_06_09                                                                   #
#..............................................................................#

# To enable execution of this file, ensure you have a inside file
# ~/.config/gdb/gdbinit
# a line starting with add-auto-load-safe-path <absolute path to this file>
# add-auto-load-safe-path /home/......../circle4/namada_minshell/.gdbinit

# to enable Debuginfo
set debuginfod enabled on
# To print structs in a more readable form
set print pretty on
# Follow child at fork()
set follow-fork-mode child
# To keep father & child under control with "inferior" command
set detach-on-fork off
#set scheduler-locking on
# Set Breakpoint at main function
break main
# Set Conditional breakpoint
break arg_pars.c:54 if i == 5
# Set other breakpoint
#break my_thread_join.c:20
#break philo.c:37
#break philo_thread.c:86
#break philo_thread.c:106
break philo_creation.c:77
break philo_thread.c:50
# set alias
run 4 800 200 200 5
