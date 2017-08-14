/*
** aff_img.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:28:26 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:44 2014 Sergen Tanguc
*/

#include "my.h"

void		aff_img_regular_off(t_data *infos)
{
  infos->path_img = infos->path_file;
  gtk_image_set_from_file(GTK_IMAGE(infos->image), infos->path_img);
}

void		aff_img_scaled_off(t_data *infos)
{
  GError	**error;

  error = NULL;
  infos->path_img = infos->path_file;
  infos->pixbuf = gdk_pixbuf_new_from_file(infos->path_img, error);
  if (infos->pixbuf == NULL)
    {
      fprintf(stderr, "Error pixbuf\n");
    }
  infos->pixbuf = gdk_pixbuf_scale_simple(infos->pixbuf,
                                          infos->spin_xl,
                                          infos->spin_yl,
                                          GDK_INTERP_BILINEAR);
  gtk_image_set_from_pixbuf(GTK_IMAGE(infos->image), infos->pixbuf);
}

void		aff_img_regular(t_data *infos)
{
  infos->path_img = "sortie.jpg";
  gtk_image_set_from_file(GTK_IMAGE(infos->image), infos->path_img);
}

void		aff_img_scaled(t_data *infos)
{
  GError	**error;

  error = NULL;
  infos->path_img = "sortie.jpg";
  infos->pixbuf = gdk_pixbuf_new_from_file(infos->path_img, error);
  if (infos->pixbuf == NULL)
    {
      fprintf(stderr, "Error pixbuf\n");
    }
  infos->pixbuf = gdk_pixbuf_scale_simple(infos->pixbuf,
                                          infos->spin_xl,
                                          infos->spin_yl,
                                          GDK_INTERP_BILINEAR);
  gtk_image_set_from_pixbuf(GTK_IMAGE(infos->image), infos->pixbuf);
}

void		aff_img(GtkButton *button, gpointer user_data)
{
  gboolean	etat;
  gboolean	etat_s;
  t_data	*infos;

  (void)button;
  infos = (t_data*)user_data;
  etat = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON
				      (infos->check_button));
  etat_s = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON
					(infos->spin_button_activate));
  if (infos->path_file != NULL)
    {
      if (etat == 0)
        generation_off(infos, etat_s);
      else
        generation_on(infos, etat_s);
    }
}
