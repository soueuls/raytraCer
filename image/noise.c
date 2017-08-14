/*
** noise.c for noise in /home/colin/Desktop/igraph/rtv1/test
** 
** Made by colin
** Login   <colin@epitech.net>
** 
** Started on  Thu Feb 13 23:19:27 2014 colin
** Last update Tue May 27 17:41:33 2014 Colin Coudray
*/

#include "igraph.h"

int		g_grad[16][3] = 
  {
    {1, 1, 0},
    {-1, 1, 0},
    {1, -1, 0},
    {-1, -1, 0},
    {1, 0, 1},
    {-1, 0, 1},
    {1, 0, -1},
    {-1, 0, -1},
    {0, 1, 1},
    {0, -1, 1},
    {0, 1, -1},
    {0, -1, -1},
    {1, 1, 0},
    {-1, 1, 0},
    {0, -1, 1},
    {0, -1, -1}
  };

double		vect_dot(int *v, double x, double y, double z)
{
  double	norme;

  norme = sqrt(s_q(x) + s_q(y) + s_q(z));
  x /= norme;
  y /= norme;
  z /= norme;
  return (*v * x + v[1] * y + v[2] * z);
}

unsigned char		*gen_tab()
{
  static int		i = 0;
  static unsigned char	*taburu;

  if (i == 0)
    {
      if ((taburu = malloc(512 * sizeof(char))) == NULL)
	exit(EXIT_FAILURE);
      srand(time(NULL));
      while (i < 512)
	taburu[i++] = (unsigned char)rand();
    }
  return (taburu);
}

int		*get_grad(int x, int y, int z)
{
  int		rand_value;
  unsigned char	*taburu;

  taburu = gen_tab();
  rand_value = taburu[(int)(z + taburu[(int)(y + taburu[(int)x & 511]) & 511]) & 511];
  return (g_grad[rand_value & 15]);
}

double		quintic_poly(double t)
{
  double	t3;

  t3 = pow(t, 3);
  return (t3 * (t * (t * 6.0 - 15.0) + 10.0));
}

void		int_and_frac(double value, int *integer, double *fractional)
{
  *integer = (int)value;
  if (value < 0)
    *integer -= 1;
  *fractional = value - *integer;
}

double		cosine_interpolate(double a, double b, double t)
{
  return ((1.0 - t) * a + t * b);
}

void		fill_var_grad(double *var, int pos[3])
{
  var[3] = vect_dot(get_grad(*pos, pos[1], pos[2]), var[0], var[1], var[2]);
  var[4] = vect_dot(get_grad(*pos, pos[1], pos[2] + 1),
		    var[0], var[1], var[2] - 1);
  var[5] = vect_dot(get_grad(*pos, pos[1] + 1, pos[2]),
		    *var, var[1] - 1, var[2]);
  var[6] = vect_dot(get_grad(*pos, pos[1] + 1, pos[2] + 1),
		    *var, var[1] + 1, var[2] + 1);
  var[7] = vect_dot(get_grad(*pos + 1, pos[1], pos[2]),
		    *var + 1, var[1], var[2]);
  var[8] = vect_dot(get_grad(*pos + 1, pos[1], pos[2] + 1),
		    *var - 1, var[1], var[2] - 1);
  var[9] = vect_dot(get_grad(*pos + 1, pos[1] + 1, pos[2]),
		    *var - 1, var[1] - 1, var[2]);
  var[10] = vect_dot(get_grad(*pos + 1, pos[1] + 1, pos[2] + 1),
		     *var - 1, var[1] - 1, var[2] - 1);
}

double		smooth_noise_3d(t_pt inter)
{
  int		pos_int[3];
  double	*var;
  double	result;

  if ((var = malloc(20 * sizeof(double))) == NULL)
    exit(EXIT_FAILURE);
  pos_int[0] = 0;
  while (pos_int[0] < 20)
    var[pos_int[0]++] = '\0';
  int_and_frac(inter.x, &pos_int[0], &var[0]);
  int_and_frac(inter.y, &pos_int[1], &var[1]);
  int_and_frac(inter.z, &pos_int[2], &var[2]);
  fill_var_grad(var, pos_int);
  var[11] = quintic_poly(var[0]);
  var[12] = quintic_poly(var[1]);
  var[13] = quintic_poly(var[2]);
  var[14] = cosine_interpolate(var[3], var[7], var[11]);
  var[15] = cosine_interpolate(var[4], var[8], var[11]);
  var[13] = cosine_interpolate(var[5], var[9], var[11]);
  var[17] = cosine_interpolate(var[6], var[10], var[11]);
  var[18] = cosine_interpolate(var[14], var[15], var[12]);
  var[19] = cosine_interpolate(var[16], var[17], var[12]);
  result = cosine_interpolate(var[18], var[19], var[13]);
  free(var);
  return (result);
}

double		noise(t_pt inter, int octave, double f, double persistance)
{
  double	nb;
  double	amplitude;
  int		i;
  t_pt		tmp;
  double	geo_lim;

  i = 0;
  nb = 0;
  amplitude = 1;
  while (i < octave)
    {
      (void)inter;
      tmp.x = (inter.x * f);
      tmp.y = (inter.y * f);
      tmp.z = (inter.z * f);
      nb += (smooth_noise_3d(tmp) * amplitude);
      amplitude *= persistance;
      f *= 2.0;
      i += 1;
    }
  geo_lim = (1.0 - persistance) / (1.0 - amplitude);
  nb *= geo_lim;
  return (nb);
}
