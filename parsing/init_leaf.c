/*
** init_leaf.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Fri Mar 14 04:04:56 2014 Colin Coudray
** Last update Sun Jun  8 18:34:45 2014 Colin Coudray
*/

#include "igraph.h"

t_init  g_taburu[NB_OBJ] =
  {
    {"sphere>", &solve_eq_sphere, &calc_normal_sphere},
    {"plan>", &solve_eq_plan, &calc_normal_plan},
    {"cylindre>", &solve_eq_cylindre, &calc_normal_cylindre},
    {"cone>", &solve_eq_cone, &calc_normal_cone},
    {"blob>", &solve_eq_blob, &calc_normal_blob},
    {"triangle>", &solve_eq_triangle, &calc_normal_triangle},
    {"cubeh>", &solve_eq_cubeh, &calc_normal_cubeh},
    {NULL}
  };

void	init_leaf_aux_aux(char **word_tab, int i, t_lif *new_obj)
{
  if (my_strcomp(word_tab[i], "radius"))
    new_obj->radius = litlget(word_tab[i + 1]);
  else if (my_strcomp(word_tab[i], "length"))
    new_obj->length = litlget(word_tab[i + 1]);
  else if (my_strcomp(word_tab[i], "checker"))
    new_obj->checker = litlget(word_tab[i + 1]);
  else if (my_strcomp(word_tab[i], "noise"))
    new_obj->noise = litlget(word_tab[i + 1]);
  else if (my_strcomp(word_tab[i], "lum_amb"))
    new_obj->lum_amb = litlget(word_tab[i + 1]) / 100.0;
  else if (my_strcomp(word_tab[i], "lum_spec"))
    new_obj->lum_spec = litlget(word_tab[i + 1]) / 100.0;
  else if (my_strcomp(word_tab[i], "lum_diff"))
    new_obj->lum_diff = litlget(word_tab[i + 1]) / 100.0;
  else if (my_strcomp(word_tab[i], "reflexion"))
    new_obj->reflexion = litlget(word_tab[i + 1]) / 100.0;
  else if (my_strcomp(word_tab[i], "transparence"))
    new_obj->transparence = litlget(word_tab[i + 1]) / 100.0;
  else if (my_strcomp(word_tab[i], "refraction"))
    new_obj->refraction = litlget(word_tab[i + 1]) / 100.0;
  else if (my_strcomp(word_tab[i], "bump_mapping"))
    new_obj->bump_mapping = litlget(word_tab[i + 1]);
  else if (my_strcomp(word_tab[i], "negatif"))
    new_obj->negatif = litlget(word_tab[i + 1]);
}

int     init_leaf_aux(char **word_tab, int i, t_lif *new_obj, int *k)
{
  int   w;

  w = 1;
  if (my_strcomp(word_tab[i], "coord"))
    new_obj->coord[(*k)++] = init_point(litlget(word_tab[i + w++]),
				      litlget(word_tab[i + 2]), litlget(word_tab[i + 3]));
  else if (my_strcomp(word_tab[i], "color"))
    new_obj->color = init_point(litlget(word_tab[i + w++]),
				litlget(word_tab[i + 2]), litlget(word_tab[i + 3]));
  else if (my_strcomp(word_tab[i], "angle"))
    new_obj->angle = init_point(rad(litlget(word_tab[i + w++])),
				rad(litlget(word_tab[i + 2])), rad(litlget(word_tab[i + 3])));
  else if (my_strcomp(word_tab[i], "texture"))
    new_obj->texture = word_tab[i + 1];
  init_leaf_aux_aux(word_tab, i, new_obj);
  return ((w == 1) ? (2) : (4));
}

void	init_leaf_side(char *name, t_lif *new_obj)
{
  int	i;

  i = 0;
  while (g_taburu[i].name != NULL && my_strcomp(name, g_taburu[i].name) == 0)
    i += 1;
  if (i == NB_OBJ)
    exit(1);
  new_obj->type = i;
  new_obj->solve_eq = g_taburu[i].solve_eq;
  new_obj->calc_normal = g_taburu[i].calc_normal;
  new_obj->texture = NULL;
}

t_lif   *init_leaf(char **word_tab, char *name)
{
  t_lif *new_obj;
  int   i;
  int   k;

  k = 0;
  i = 0;
  if ((new_obj = malloc(sizeof(t_lif))) == NULL)
    return (NULL);
  if (name != NULL)
    init_leaf_side(name, new_obj);
  i = 0;
  if (word_tab != NULL)
    while (word_tab[i])
      {
        i += init_leaf_aux(word_tab, i, new_obj, &k);
        if (i > tab_len(word_tab))
          exit(1);
      }
  new_obj->next = new_obj;
  new_obj->prev = new_obj;
  return (new_obj);
}
