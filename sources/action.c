/*
** action.c for  in /home/karst_j/PSU_2015_philo/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Fri Mar 11 09:44:02 2016 Julien Karst
** Last update Fri Mar 11 09:48:23 2016 Julien Karst
*/

#include		"philo.h"

void			state_sleep(t_philo *data)
{
  if (sem_trywait(&sem) == 0)
    {
      pthread_mutex_lock(&(data->mu));
      pthread_mutex_lock(&(data->next->mu));
      eat(data);
      sem_post(&sem);
    }
  else
    {
      pthread_mutex_lock(&(data->mu));
      think(data);
    }
}

void			state_think(t_philo *data)
{
  sem_wait(&sem);
  pthread_mutex_lock(&(data->mu));
  pthread_mutex_lock(&(data->next->mu));
  eat(data);
  sem_post(&sem);
}
