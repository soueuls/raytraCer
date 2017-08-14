/*
** init.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:17:15 2014 Sergen Tanguc
** Last update Sun Jun  8 20:53:49 2014 Sergen Tanguc
*/

#include "my.h"

void	init_data_open(t_open_data *data)
{
  data->fichier = NULL;
  data->contents = NULL;
  data->p_text_buffer = NULL;
  data->contents = NULL;
}

void	init_box_img(t_data *infos)
{
  infos->image = gtk_image_new_from_file(infos->path_file);
  gtk_box_pack_start(GTK_BOX(infos->vbox), infos->image, TRUE, FALSE, 5);
  gtk_box_set_homogeneous(GTK_BOX(infos->vbox), FALSE);
  gtk_box_set_spacing(GTK_BOX(infos->vbox), 0);
}

void	init_box(t_data *infos)
{
  infos->vbox = gtk_vbox_new(TRUE, 2);
  gtk_widget_set_size_request(infos->vbox, 1920, 1080);
  gtk_container_add(GTK_CONTAINER(infos->window), infos->vbox);
  gtk_box_pack_start(GTK_BOX(infos->vbox), infos->label_main, TRUE, FALSE, 10);
  add_second_box(infos);
}

void	init_window(t_data *infos)
{
  infos->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(infos->window), "RayTool - RayTracer Viewer");
  infos->spin_xl = 500;
  infos->spin_yl = 500;
}

void	init_label(t_data *infos)
{
  gchar	*utf8;

  infos->label_main = gtk_label_new(NULL);
  utf8 = g_locale_to_utf8
    ("<span face=\"Courier New 500\"><b>Welcome to RayTracer Viewer</b></span>\n",
     -1, NULL, NULL, NULL);
  gtk_label_set_markup(GTK_LABEL(infos->label_main), utf8);
  g_free(utf8);
  infos->path_file = NULL;
  infos->path_img = NULL;
  infos->path_file = malloc(sizeof(char) * 4096);
  infos->path_img = malloc(sizeof(char) * 4096);
  if (infos->path_file == NULL || infos->path_img == NULL)
    {
      fprintf(stderr, "Error malloc\n");
      exit(1);
    }
}
