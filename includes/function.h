/*
** function.h for RT in /home/coudra/Desktop/igraph/RT
**
** Made by Colin Coudray
** Login   <coudra@epitech.net>
**
** Started on  Tue Mar 18 17:47:38 2014 Colin Coudray
** Last update Sun Jun  8 16:41:16 2014 Colin Coudray
*/

#ifndef FUNCTION_H_
# define FUNCTION_H_

#include <stdio.h>

long double	ab_s(long double);
t_pt		add_color(t_pt, t_pt);
t_pt		background_img(int);
void		black_and_white(t_img*);
char		*block_split(char*, int, int);
t_btree		*build_kdtree(t_lif*);
t_pt		bump_normal(t_pt, t_pt);
t_pt		calc_color(t_sst*, t_pt, t_pt);
t_pt		calc_color_aux(t_sst*, t_rec, long double, t_lif);
t_pt		calc_color_net(t_sst*, t_rec);
t_pt		calc_inter(long double, t_pt, t_pt);
t_pt		calc_normal_blob(t_lif*, t_pt);
t_pt		calc_normal_cone(t_lif*, t_pt);
t_pt		calc_normal_cubeh(t_lif*, t_pt);
t_pt		calc_normal_cylindre(t_lif*, t_pt);
t_pt		calc_normal_plan(t_lif*, t_pt);
t_pt		calc_normal_sphere(t_lif*, t_pt);
t_pt		calc_normal_tore(t_lif*, t_pt);
t_pt		calc_normal_triangle(t_lif*, t_pt);
t_pt		calc_ray(t_pt, t_pt);
t_pt		calc_refl(t_lif*, t_pt, t_pt);
long double	calc_solution(t_sst*, t_lif*, t_pt, t_pt);
t_pt		calc_transp(t_lif*, t_pt, t_pt, long double*);
t_pt		calc_vect(int, int, t_cam);
t_pt		check_color(t_pt);
void		clear_space(char[1024]);
t_pt		color_noise(t_lif*, t_pt, t_pt, long double);
t_pt		color_obj(t_lif*, t_pt, t_lum*, t_pt);
void		compress_jpeg(t_img*, char*);
char		*convert_to_minilibx(t_img*);
char		*convert_to_jpeg(t_img*);
void		convert_ycbcr(char*, char*);
t_img		decompress_jpeg(char*);
void		draw_edge(t_img*);
void		draw_img(t_img*, const char*);
t_pt		effects(t_lif*, t_pt, long double, t_pt);
t_pt		eq_3rd(t_pt, long double);
t_pt		eq_4th(t_pt, t_pt, long double*);
void		fill_rec(t_rec*, long double, t_lif*, int);
t_pt		finalise_color(t_pt, int);
void		gaussian_blur(t_img*);
int		gere_expose(t_img*);
int		gere_key(int, t_img*);
char		*get_next_line(const int);
void		go_sepia(t_img*);
void		init_cam(int, t_sst*);
t_mlx		*init_main();
t_lif		*init_leaf(char**, char*);
t_lum		*init_light(char**);
char		*init_obj(int, t_sst*, char*);
t_pt		init_point(long double, long double, long double);
char		*init_spot(int, t_sst*);
int		is_edge(t_img*, int, int);
int		litlget(char*);
t_pt		load_celshader(long double);
t_pt		melt_color(t_pt, t_pt, double);
int		my_get_until(char[1024], char, int);
void		my_go_to(char[1024], char, int);
t_img		*my_new_img(t_mlx*, char*);
int		my_putchar(int);
int		my_putstr(char*);
char		*my_strcat(char*, char*);
int		my_strcomp(char*, char*);
char		*my_strcpy(char*, char*);
int		my_strlen(char*);
char		**my_str_to_word_tab(char*, char*);
double		noise(t_pt, double);
t_pt		normalise(t_pt);
FILE		*open_file(char*, char*);
t_sst		*parsing(const char*);
long double	rad(long double);
t_pt		rota(t_pt, t_pt);
void	       	save_img(t_img*);
long double	solve_eq_blob(t_lif*, t_pt, t_pt);
long double	solve_eq_cone(t_lif*, t_pt, t_pt);
long double	solve_eq_cubeh(t_lif*, t_pt, t_pt);
long double	solve_eq_cylindre(t_lif*, t_pt, t_pt);
long double	solve_eq_plan(t_lif*, t_pt, t_pt);
long double	solve_eq_sphere(t_lif*, t_pt, t_pt);
long double	solve_eq_tore(t_lif*, t_pt, t_pt);
long double	solve_eq_triangle(t_lif*, t_pt, t_pt);
long double	s_q(long double);
int		tab_len(char**);
t_pt		transl(t_pt, t_pt);

#endif /* FUNCTION_H_ */
