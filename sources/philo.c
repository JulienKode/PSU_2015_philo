/*
** philo.c for Philosophe in /home/karst_j/PSU_2015_philo/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Tue Mar  1 17:30:12 2016 Julien Karst
** Last update Fri Mar 11 09:44:58 2016 Julien Karst
*/

#include	"philo.h"

static int	finish(t_philo *data)
{
  if (data->nb_eat >= data->e)
    return (0);
  return (1);
}

void		*thread_philo(void *in)
{
  t_philo	*data;

  data = (t_philo *)in;
  while (1)
    {
      if (data->state == THINK)
	state_think(data);
      else if (data->state == EAT)
	sleep(data);
      else if (data->state == SLEEP)
	state_sleep(data);
      if (finish(data) == 0)
	return (NULL);
    }
  return (NULL);
}

void		main_philo(t_info *info)
{
  t_philo	*data;
  int		i;

  create_all(info);
  sem_init(&sem, 0, (info->p / 2));
  data = info->data;
  i = 0;
  data = info->data;
  while (i < data->p)
    {
      pthread_create(&(data->thread), NULL, thread_philo, data);
      data = data->next;
      i++;
    }
  data = info->data;
  i = 0;
  while (i < data->p)
    {
      pthread_join(data->thread, NULL);
      data = data->next;
      i++;
    }
}
