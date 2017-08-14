/*
** compress_jpeg.c for compress_jpeg in /home/soueuls/JPEG
** 
** Made by Swann Polydor
** Login   <soueuls@epitech.net>
** 
** Started on  Tue Jun  3 20:36:02 2014 Swann Polydor
** Last update Sun Jun  8 20:05:58 2014 Colin Coudray
*/

#include "igraph.h"
#include "jpeglib.h"

void				init_jpeg_info(struct jpeg_compress_struct *cinfo, t_img *img)
{
  cinfo->image_width = img->width;
  cinfo->image_height = img->height;
  cinfo->input_components = 3;
  cinfo->in_color_space = JCS_RGB;
  jpeg_set_defaults(cinfo);
  jpeg_set_quality(cinfo, 100, TRUE);
  cinfo->dct_method = JDCT_FLOAT;
}

void				compress_jpeg(t_img *img, char *outfile)
{
  struct jpeg_compress_struct	cinfo;
  struct jpeg_error_mgr		jerr;
  JSAMPROW			row_pointer[1];
  FILE				*file;
  int				row_stride;

  file = open_file(outfile, "wb");
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, file);
  init_jpeg_info(&cinfo, img);
  jpeg_start_compress(&cinfo, TRUE);
  img->data = convert_to_jpeg(img);
  row_stride = cinfo.image_width * cinfo.input_components;
  while (cinfo.next_scanline < cinfo.image_height)
    {
      row_pointer[0] = &img->data[cinfo.next_scanline * row_stride];
      jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);
  fclose(file);
}
