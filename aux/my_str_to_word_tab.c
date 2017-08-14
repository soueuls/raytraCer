/*
** my_str_to_word_tab.c for minishell2 in /home/colin/Desktop/prog_elem/allum1
** 
** Made by colin
** Login   <colin@epitech.net>
** 
** Started on  Wed Feb 12 16:33:32 2014 colin
** Last update Wed Feb 12 19:04:36 2014 colin
*/

#include "igraph.h"

int	match_delim(char c, char *delim)
{
  int	i;

  i = 0;
  while (delim[i] != '\0')
    {
      if (c == delim[i])
	return (1);
      i = i + 1;
    }
  return (0);
}

char	*my_strcpy(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s2[i])
    {
      s1[i] = s2[i];
      i += 1;
    }
  s1[i] = '\0';
  return (s1);
}

int	count_words(char *line, char *delim)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (line[i])
    {
      while (match_delim(line[i], delim) && line[i])
	i += 1;
      if (!match_delim(line[i], delim) && line[i])
	nb += 1;
      while (!match_delim(line[i], delim) && line[i])
	i += 1;
    }
  return (nb);
}

char	**my_str_to_word_tab(char *line, char *delim)
{
  char	**tab;
  char	*ptr;
  int	nb_words;
  int	i;

  nb_words = count_words(line, delim);
  tab = malloc(sizeof(char*) * (nb_words + 1) + my_strlen(line) + 1);
  if (tab == NULL)
    exit(1);
  ptr = (char*)tab;
  ptr += sizeof(char*) * (nb_words + 1);
  ptr = my_strcpy(ptr, line);
  i = 0;
  while (*ptr != '\0')
    {
      while (match_delim(*ptr, delim) && *ptr != '\0')
	*ptr++ = '\0';
      if (!(match_delim(*ptr, delim)) && *ptr != '\0')
	tab[i++] = ptr;
      while (!(match_delim(*ptr, delim)) && *ptr != '\0')
	ptr++;
    }
  tab[i] = NULL;
  return (tab);
}
