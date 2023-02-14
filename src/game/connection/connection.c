/*
** EPITECH PROJECT, 2021
** Connection for Navy
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "navy.h"

void sig_handler(int signum, siginfo_t *info, void *context)
{
    signal_struct.signalReceived = signum;
    signal_struct.signalPid = info->si_pid;
}

void player1_connection(data_navy_t *data_navy, char **argv)
{
    signal_struct.pid_p1 = getpid();
    data_navy->player1.path = argv[1];
    my_printf("my_pid: %d\n", signal_struct.pid_p1);
    my_printf("waiting for ennemy connection...\n\n");
    while (signal_struct.signalReceived == 0)
        if (signal_struct.signalReceived == SIGUSR2)
            signal_struct.signalReceived = SIGUSR2;
    my_printf("enemy connected\n");
}

void pid_in_file(int pid)
{
    int fd = open(".pid", O_WRONLY);
    char *str_pid = my_put_nbr_in_str(pid);

    write(fd, str_pid, my_strlen(str_pid));
    close(fd);
}

void player2_connection(data_navy_t *data_navy, char **argv)
{
    signal_struct.pid_p2 = getpid();
    data_navy->player2.path = argv[2];
    if (kill(my_getnbr(argv[1]), SIGUSR2) == 0) {
        my_printf("my_pid: %d\n", signal_struct.pid_p2);
        pid_in_file(getpid());
        my_printf("succesfully connected\n");
    } else
        data_navy->error = 1;
}

void terminals_connection(data_navy_t *data_navy, int argc, char **argv)
{
    char *path;
    struct sigaction act;

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &sig_handler;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    data_navy->error = 0;
    if (argc == 2)
        player1_connection(data_navy, argv);
    else
        player2_connection(data_navy, argv);
}
