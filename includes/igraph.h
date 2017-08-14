/*
** igraph.h for RT in /home/coudra/Desktop/igraph/RT
**
** Made by Colin Coudray
** Login   <coudra@epitech.net>
**
** Started on  Tue Mar 18 17:41:48 2014 Colin Coudray
** Last update Tue Jun 23 18:57:37 2015 Coudray Colin
*/

#ifndef IGRAPH_H_
# define IGRAPH_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <mlx.h>
#include "struct.h"
#include "function.h"

#include <stdio.h>

#define  HEIGHT			(900)
#define  WIDTH			(900)
#define  FOCALE			(900)

#define	 NB_OBJ			(8)

#define  LUM_AMB		(0)

#define  EQ_MARGIN		(0.0000001)
#define  MAXCHAR		(255)

#define  RES_N			(50)
#define  STRIURE_BOIS		(20)
#define  PHONG_EXP		(64)
#define  L_CARR			(obj->checker)
#define	 FIELD_DEPTH		(14)
#define	 OCTAVE			(1)
#define  FREQ			(1.0 / 50.0)
#define  PERSIST		(2.0)

#define  V1			(0.0)
#define  V2			(0.33)
#define  V3			(0.66)
#define  V4			(1.0)

#define  RN			(0)
#define  GN			(0)
#define  BN			(0)

#define  BLUR_SHAD		(5)
#define  NB_RAY_SHAD		(50)
#define  BLUR_SHAD_OR_NOT	(0)

#define  CELSHADING		(0)
#define  B_A_W			(0)
#define  SEPIA			(0)

#define	 BLOB			(4)
#define  THRESHOLD		(0.17)
#define  PAS_BLOB		(0.001)
#define  PREC_FIELD		(100000)

#define  BACKGROUND_IMG		"img.jpg"

#endif /* IGRAPH_H_ */
