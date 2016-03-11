/*
** philo.h for  in /home/karst_j/PSU_2015_philo/includes
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Tue Mar  1 09:09:09 2016 Julien Karst
** Last update Fri Mar 11 09:49:03 2016 Julien Karst
*/

#ifndef			PHILO_H_
# define		PHILO_H_

#include		<stdio.h>
#include		<stdlib.h>
#include		<pthread.h>
#include		<string.h>
#include		<semaphore.h>
#include		"extern.h"
#include		"my.h"

#define UNINI		-1
#define EAT		1
#define THINK		2
#define SLEEP		3

typedef struct		s_philo
{
  pthread_mutex_t	mu;
  pthread_t		thread;
  int			state;
  int			nb_eat;
  struct s_philo	*next;
  struct s_philo	*prev;
  int			e;
  int			p;
  int			pos;
}			t_philo;

typedef struct		s_info
{
  int			p;
  int			e;
  t_philo		*data;
}			t_info;

extern sem_t		sem;

void			think(t_philo *data);
void			eat(t_philo *data);
void			sleep(t_philo *data);
void			free_philo(t_philo *start);
void			create_all(t_info *info);
void			main_philo(t_info *info);
void			*thread_philo(void *in);
void			state_sleep(t_philo *data);
void			state_think(t_philo *data);

#endif			/* PHILO_H_ */
