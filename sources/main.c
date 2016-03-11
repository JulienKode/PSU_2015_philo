/*
** main.c for Philosophe in /home/karst_j/PSU_2015_philo/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Tue Mar  1 09:08:13 2016 Julien Karst
** Last update Fri Mar 11 10:31:14 2016 Julien Karst
*/

#include	"philo.h"

static void	main_exec(int ac, char **argv, t_info *info)
{
  int		i;

  i = 1;
  while (i < ac)
    {
      if (strcmp("-p", argv[i]) == 0)
	if (my_str_isnum(argv[++i]))
	  info->p = my_getnbr(argv[i]);
      if (strcmp("-e", argv[i]) == 0)
	if (my_str_isnum(argv[++i]))
	  info->e = my_getnbr(argv[i]);
      i++;
    }
}

static void	main_start(int ac, char **argv, t_info *info)
{
  RCFStartup(ac, argv);
  main_philo(info);
  RCFCleanup();
}

int		main(int ac, char **argv)
{
  t_info	info;

  info.e = -1;
  info.p = -1;
  main_exec(ac, argv, &info);
  if (info.p > 1 && info.e > 0)
    main_start(ac, argv, &info);
  else
    my_exit2("Error -> Invalid argument");
  return (0);
}
