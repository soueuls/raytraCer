/*
** noise.c for noise in /home/colin/Desktop/igraph/rtv1/test
** 
** Made by colin
** Login   <colin@epitech.net>
** 
** Started on  Thu Feb 13 23:19:27 2014 colin
** Last update Wed Jun  4 21:42:33 2014 Colin Coudray
*/

#include "igraph.h"

#define CTE_PROJ (0.5)

static long double g_radient2[][2] =
  {
    {M_SQRT1_2,M_SQRT1_2},
    {-M_SQRT1_2,M_SQRT1_2},
    {M_SQRT1_2,-M_SQRT1_2},
    {-M_SQRT1_2,-M_SQRT1_2},
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
  };

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
	taburu[i++] = ab_s((char)rand());
    }
  return (taburu);
}

int		gi_x(int x, int x0, int y0)
{
  int		ii;
  int		jj;
  unsigned char	*taburu;

  taburu = gen_tab();
  ii = x0 & 255;
  jj = y0 & 255;
  if (x == 0)
    return (taburu[(int)ab_s((int)(char)ab_s(ii + taburu[jj]))] % 8);
  else if (x == 1)
    return (taburu[(int)ab_s((int)(char)ab_s(ii + 1 + taburu[jj]))] % 8);
  else if (x == 2)
    return (taburu[(int)ab_s((int)(char)ab_s(ii + taburu[jj + 1]))] % 8);
  else
    return (taburu[(int)ab_s((int)(char)ab_s(ii + 1 + taburu[jj + 1]))] % 8);
}

long double	*gradient_2d(long double x, long double y, int x0, int y0)
{
  long double	tempX;
  long double	tempY;
  long double	*stuv;

  if ((stuv = malloc(4 * sizeof(long double))) == NULL)
    exit(-1);
  tempX = x - x0;
  tempY = y - y0;
  stuv[0] = g_radient2[gi_x(0, x0, y0)][0] * tempX +
    g_radient2[gi_x(0, x0, y0)][1] * tempY;
  tempX = x - (x0 + 1);
  tempY = y - y0;
  stuv[1] = g_radient2[gi_x(1, x0, y0)][0] * tempX +
    g_radient2[gi_x(1, x0, y0)][1] * tempY;
  tempX = x - x0;
  tempY = y - (y0 + 1);
  stuv[2] = g_radient2[gi_x(2, x0, y0)][0] * tempX +
    g_radient2[gi_x(2, x0, y0)][1] * tempY;
  tempX = x - (x0 + 1);
  tempY = y - (y0 + 1);
  stuv[3] = g_radient2[gi_x(3, x0, y0)][0] * tempX +
    g_radient2[gi_x(3, x0, y0)][1] * tempY;
  return (stuv);
}

double		noise(t_pt inter, double f)
{
  int		x0;
  int		y0;
  long double	tmp;
  long double	*stuv;
  long double	Cx;
  long double	Cy;
  long double	Li1;
  long double	Li2;
  long double	x;
  long double	y;

  x = (inter.x + CTE_PROJ * inter.z) / f;
  y = (inter.y + CTE_PROJ / 2.0 * inter.z) / f;
  x0 = (x >= 0 ? (int)(x) : (int)x - 1);
  y0 = (y >= 0 ? (int)(y) : (int)y - 1);
  stuv = gradient_2d(x, y, x0, y0);
  tmp = x - x0;
  Cx = 3 * tmp * tmp - 2 * tmp * tmp * tmp;
  Li1 = stuv[0] + Cx * (stuv[1] - stuv[0]);
  Li2 = stuv[2] + Cx * (stuv[3] - stuv[2]);
  tmp = y - y0;
  Cy = 3 * tmp * tmp - 2 * tmp * tmp * tmp;
  free(stuv);
  return (Li1 + Cy * (Li2 - Li1));
}
