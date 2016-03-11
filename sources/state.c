/*
** state.c for Philosophe in /home/karst_j/PSU_2015_philo/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Wed Mar  2 09:33:22 2016 Julien Karst
** Last update Wed Mar  9 13:32:44 2016 Julien Karst
*/

#include	"philo.h"

void		think(t_philo *data)
{
  lphilo_take_chopstick(&(data->mu));
  data->state = THINK;
  lphilo_think();
  lphilo_release_chopstick(&(data->mu));
  pthread_mutex_unlock(&(data->mu));
}

void		eat(t_philo *data)
{
  lphilo_take_chopstick(&(data->mu));
  lphilo_take_chopstick(&(data->next->mu));
  data->nb_eat += 1;
  data->state = EAT;
  lphilo_eat();
  lphilo_release_chopstick(&(data->mu));
  lphilo_release_chopstick(&(data->next->mu));
  pthread_mutex_unlock(&(data->mu));
  pthread_mutex_unlock(&(data->next->mu));
}

void		sleep(t_philo *data)
{
  lphilo_sleep();
  data->state = SLEEP;
}
