/*
** list.c for Philosophe in /home/karst_j/PSU_2015_philo/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sat Mar  5 17:30:40 2016 Julien Karst
** Last update Fri Mar 11 10:29:19 2016 Julien Karst
*/

#include	"philo.h"

static void	state_philo(t_philo *tmp)
{
  if ((tmp->pos % 2) == 0)
    tmp->state = EAT;
  else
    tmp->state = SLEEP;
  if ((tmp->pos) == (tmp->p - 1) && (tmp->p % 2) == 1)
    tmp->state = THINK;
}

static void	init_philo(t_philo *tmp, int p, int e, int pos, t_philo *prev)
{
  tmp->nb_eat = 0;
  tmp->e = e;
  tmp->p = p;
  tmp->pos = pos;
  tmp->prev = prev;
}

static t_philo	*new_philo(t_philo *prev, int p, int e, int pos)
{
  t_philo	*tmp;
  t_philo	*start;

  start = prev;
  if (prev)
    while (prev->next)
      prev = prev->next;
  if ((tmp = malloc(1 * sizeof(t_philo))) == NULL)
    return (NULL);
  init_philo(tmp, p, e, pos, prev);
  state_philo(tmp);
  pthread_mutex_init(&(tmp->mu), NULL);
  if (prev != NULL)
    prev->next = tmp;
  tmp->next = NULL;
  if (start)
    return (start);
  return (tmp);
}

void		free_philo(t_philo *start)
{
  t_philo	*tmp;

  if (start)
    {
      while (start)
	{
	  tmp = start;
	  start = start->next;
	  if (tmp)
	    free(tmp);
	}
    }
}

void		create_all(t_info *info)
{
  t_philo	*start;
  t_philo	*res;
  int		i;

  i = -1;
  res = NULL;
  while (++i < info->p)
    res = new_philo(res, info->p, info->e, i);
  info->data = res;
  start = res;
  while (res->next != NULL)
    res = res->next;
  res->next = start;
  start->prev = res;
}
