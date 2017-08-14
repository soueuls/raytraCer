/*
** scrol.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:31:41 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:30 2014 Sergen Tanguc
*/

#include "my.h"

void	add_check_scale(t_data *infos)
{
  gchar	*label;

  label = g_locale_to_utf8("Activation Scale ?", -1, NULL, NULL, NULL);
  infos->spin_button_activate = gtk_check_button_new_with_label(label);
  g_free(label);
  gtk_box_pack_start(GTK_BOX(infos->hbox), infos->spin_button_activate,
		     FALSE, FALSE, 1);
}

void	add_scroll_edit_window(t_data *infos)
{
  infos->scroll_bar = gtk_scrolled_window_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(infos->window_edit), infos->scroll_bar);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(infos->scroll_bar),
					infos->box_view);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(infos->scroll_bar),
				 GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
}
