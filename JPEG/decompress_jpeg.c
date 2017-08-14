/*
** decompress_jpeg.c for decompress_jpeg in /home/soueuls/JPEG
** 
** Made by Swann Polydor
** Login   <soueuls@epitech.net>
** 
** Started on  Tue Jun  3 20:34:56 2014 Swann Polydor
** Last update Fri Jun  6 16:57:40 2014 Colin Coudray
*/

#include "igraph.h"
#include "jpeglib.h"

char		*convert_to_minilibx(t_img *img);

char		*fill_image(struct jpeg_decompress_struct *cinfo, int number_of_pixels)
{
  JSAMPROW	buffer[1];;
  char		*image;
  unsigned int 	i;
  int		j;

  if ((image = malloc(number_of_pixels * cinfo->output_components)) == NULL)
    exit(1);
  buffer[0] = malloc(cinfo->output_width * cinfo->output_components);
  j = 0;
  while (cinfo->output_scanline < cinfo->output_height)
    {
      jpeg_read_scanlines(cinfo, buffer, 1);
      i = 0;
      while (i < cinfo->output_width * cinfo->output_components)
	image[j++] = buffer[0][i++];
    }
  return (image);
}

FILE	*open_file(char *file_to_open, char *mode)
{
  FILE	*file;

  if ((file = fopen(file_to_open, mode)) == NULL)
    {
      printf("Can't open %s\n", file_to_open);
      exit(1);
    }
  else
    return (file);
}

t_img	decompress_jpeg(char *infile)
{
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr		jerr;
  FILE				*file;
  int				number_of_pixels;
  t_img				img;

  file = open_file(infile, "rb");
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);
  jpeg_stdio_src(&cinfo, file);
  jpeg_read_header(&cinfo, TRUE);
  jpeg_start_decompress(&cinfo);
  img.width = cinfo.output_width;
  img.height = cinfo.output_height;
  number_of_pixels = img.width * img.height;
  img.data = fill_image(&cinfo, number_of_pixels);
  img.data = convert_to_minilibx(&img);
  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);
  fclose(file);
  return (img);
}
