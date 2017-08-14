/*
** box.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:32:26 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:39 2014 Sergen Tanguc
*/

#include "my.h"

void		add_second_box(t_data *infos)
{
  infos->hbox = gtk_hbox_new(TRUE, 2);
  gtk_box_pack_start(GTK_BOX(infos->vbox), infos->hbox, TRUE, FALSE, 20);
  add_toggle_button(infos);
  infos->label_choice = gtk_label_new("Please choose an image =>");
  infos->button[0] = gtk_button_new_with_label("File");
  infos->button[1] = gtk_button_new_with_label("Go !");
  infos->button[2] = gtk_button_new_with_label("Edit file");
  infos->button[4] = gtk_button_new_with_label("Scale image");
  gtk_box_pack_start(GTK_BOX(infos->hbox), infos->label_choice, TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(infos->hbox), infos->button[0], TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(infos->hbox), infos->button[2], TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(infos->hbox), infos->button[4], TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(infos->hbox), infos->button[1], TRUE, FALSE, 0);
  gtk_box_set_spacing(GTK_BOX(infos->hbox), 1);
  gtk_widget_set_size_request(infos->button[0], 150, 30);
  gtk_widget_set_size_request(infos->button[1], 150, 30);
  gtk_widget_set_size_request(infos->button[2], 150, 30);
  gtk_widget_set_size_request(infos->button[4], 150, 30);
}
