/*
** my.h for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Mon Jun  2 15:41:31 2014 Sergen Tanguc
** Last update Sun Jun  8 21:08:58 2014 Colin Coudray
*/

#ifndef _MY_H_
# define _MY_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct	s_document
{
  gchar		*path_file;
  gboolean	sauve;
  GtkTextView	*p_text_view;
}		t_document;

typedef struct	s_docs
{
  GList		*tous;
  t_document	*actif;
}		t_docs;

extern t_docs	docs;

typedef struct	s_open_data
{
  FILE		*fichier;
  gchar		*contents;
  gchar		*locale;
  GtkTextIter	start;
  GtkTextIter	end;
  GtkTextBuffer	*p_text_buffer;
}		t_open_data;

typedef struct	s_data
{
  GtkWidget	*window;
  GtkWidget	*label_main;
  GtkWidget	*label_choice;
  GtkWidget	*button[5];
  GtkWidget	*vbox;
  GtkWidget	*hbox;
  GtkWidget	*file;
  const gchar	*path_file;
  const gchar	*path_img;
  GtkWidget	*image;
  GdkPixbuf	*pixbuf;
  GtkWidget	*window_edit;
  GtkWidget	*text_view;
  GtkWidget	*box_view;
  GtkTextBuffer	*text_buffer;
  GtkWidget	*scroll_bar;
  GtkWidget	*button_save_file;
  GtkWidget	*check_button;
  GtkWidget	*window_spin;
  GtkWidget	*spin_button_activate;
  GtkWidget	*box_spin;
  GtkWidget	*button_default;
  GtkWidget	*spin_x;
  GtkWidget	*spin_y;
  int		spin_xl;
  int		spin_yl;
}		t_data;

typedef struct	s_open_cont
{
  gchar		*contents;
  gchar		*utf8;
  GtkTextIter	iter;
}		t_open_cont;

void		my_destroy_window(GtkWidget *widget, gpointer pdata);
void		aff_img_scaled(t_data *infos);
void		generation_img(t_data *infos);
void		generation_on(t_data *infos, gboolean etat_s);
void		generation_off(t_data *infos, gboolean etat_s);
void		aff_img(GtkButton *button, gpointer user_data);
void		img_selection_button(t_data *infos);
void		take_path(GtkButton *button, gpointer user_data);
void		search_file(GtkButton *button, gpointer user_data);
void		file_selection_button(t_data *infos);
void		init_label(t_data *infos);
void		init_window(t_data *infos);
void		modif_generation(GtkButton *button, gpointer user_data);
void		default_spin(GtkButton *button, gpointer user_data);
void		add_default_button(t_data *infos);
void		aff_value_spin(GtkSpinButton *spinbutton, GtkScrollType arg1, gpointer user_data);
void		aff_value_spi_other(GtkSpinButton *spinbutton, gpointer user_data);
void		add_spin_bar(t_data *infos);
void		save_spin(GtkButton *button, gpointer user_data);
void		spin_button(GtkButton *button, gpointer user_data);
void		spin_selection_button(t_data *infos);
void		add_check_scale(t_data *infos);
void		add_toggle_button(t_data *infos);
void		add_second_box(t_data *infos);
void		init_box_img(t_data *infos);
void		init_box(t_data *infos);
void		open_file (t_data *infos);
void		add_scroll_edit_window(t_data *infos);
void		modif_text(GtkButton *button, gpointer user_data);
void		init_data_open(t_open_data *data);
void		save_file(GtkButton *button, gpointer user_data);
void		button_save_file(t_data *infos);
void		edit_func(GtkButton *button, gpointer user_data);
void		edit_selection_button(t_data *infos);
void		aff_img_regular(t_data *infos);
void		aff_img_regular_off(t_data *infos);
void		aff_img_scaled_off(t_data *infos);

#endif
