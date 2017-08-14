/*
** struct.h for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Mar 18 17:45:55 2014 Colin Coudray
** Last update Fri Jun  6 15:50:57 2014 Colin Coudray
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct  s_mlx
{
  void          *mlx_ptr;
  void          *win_ptr;
}               t_mlx;

typedef struct  s_img
{
  char          *img;
  char          *data;
  char		*name;
  int		width;
  int		height;
  int           bpp;
  int           sizel;
  int           endian;
  t_mlx         *mlx;
}               t_img;

typedef struct s_btree t_btree;

struct		s_btree
{
  void		*data;
  t_btree	*left;
  t_btree	*right;
};

typedef struct  s_pt
{
  long double	x;
  long double	y;
  long double	z;
}               t_pt;

typedef struct  s_cam
{
  t_pt          coord;
  t_pt          angle;
}               t_cam;

typedef struct  s_lum
{
  t_pt          coord;
  t_pt          color;
  struct s_lum  *next;
  struct s_lum  *prev;
}               t_lum;

typedef struct  s_lif
{
  char          type;
  t_pt          coord[3];
  t_pt          angle;
  t_pt          color;
  long          radius;
  long          length;
  int		checker;
  int		noise;
  int		bump_mapping;
  int		negatif;
  long double	lum_spec;
  long double	lum_diff;
  long double	lum_amb;
  long double	reflexion;
  long double	transparence;
  long double	refraction;
  char		*texture;
  long double   (*solve_eq)(struct s_lif*, t_pt, t_pt);
  t_pt          (*calc_normal)(struct s_lif*, t_pt);
  struct s_lif  *next;
  struct s_lif  *prev;
}               t_lif;

typedef struct  s_init
{
  char          *name;
  long double	(*solve_eq)(struct s_lif*, t_pt, t_pt);
  t_pt          (*calc_normal)(struct s_lif*, t_pt);
}               t_init;

typedef struct  s_sst
{
  t_cam         cam;
  t_lum         *light;
  t_lif         *obj;
  t_btree	*kdtree;
}               t_sst;

typedef struct	s_rec
{
  t_pt		color;
  int		stack;
  long double	n;
  t_pt		coord;
  t_pt		vect;
}		t_rec;

#endif /* STRUCT_H_ */
