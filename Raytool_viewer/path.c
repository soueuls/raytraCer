/*
** path.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:29:13 2014 Sergen Tanguc
** Last update Sun Jun  8 20:54:07 2014 Sergen Tanguc
*/

#include "my.h"

void		take_path(GtkButton *button, gpointer user_data)
{
  GtkWidget	*dialog;
  t_data	*infos;

  (void)button;
  infos = (t_data*)user_data;
  infos->path_file = gtk_file_selection_get_filename
    (GTK_FILE_SELECTION(infos->file));
  dialog = gtk_message_dialog_new(GTK_WINDOW(infos->file),
                                  GTK_DIALOG_MODAL,
                                  GTK_MESSAGE_INFO,
                                  GTK_BUTTONS_OK,
                                  "Vous avez choisi :\n%s", infos->path_file);
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
  gtk_widget_destroy(infos->file);
}

void		search_file(GtkButton *button, gpointer user_data)
{
  t_data	*infos;

  (void)button;
  infos = (t_data*)user_data;
  infos->file = gtk_file_selection_new("Ouvrir un fichier");
  gtk_widget_show(infos->file);
  g_signal_connect(GTK_FILE_SELECTION(infos->file)->ok_button, "clicked",
		   G_CALLBACK(take_path), infos);
}

static void	open_file_init_data(t_open_cont *data, t_data *infos)
{
  data->contents = NULL;
  data->utf8 = NULL;
  infos->text_buffer = NULL;
}

void		open_file(t_data *infos)
{
  t_open_cont	data;

  open_file_init_data(&data, infos);
  g_return_if_fail (infos->path_file && infos->text_view);
  {
    if (g_file_get_contents(infos->path_file, &data.contents, NULL, NULL))
      {
        docs.actif = g_malloc(sizeof(*docs.actif));
        docs.actif->path_file = g_strdup(infos->path_file);
	infos->text_buffer = gtk_text_view_get_buffer
	  (GTK_TEXT_VIEW(infos->text_view));
        gtk_text_buffer_get_iter_at_line(infos->text_buffer, &data.iter, 0);
	data.utf8 = g_locale_to_utf8(data.contents, -1, NULL, NULL, NULL);
        docs.actif->p_text_view = GTK_TEXT_VIEW(infos->text_view);
        docs.actif->sauve = TRUE;
        g_free(data.contents);
        data.contents = NULL;
        gtk_text_buffer_insert(infos->text_buffer,
			       &data.iter, data.utf8, -1);
        g_free(data.utf8);
        data.utf8 = NULL;
      }
    else
      fprintf(stderr, "Impossible d'ouvrir le fichier");
  }
}

void		save_file(GtkButton *button, gpointer user_data)
{
  t_data	*infos;
  t_open_data	data;

  (void)button;
  infos = (t_data*)user_data;
  init_data_open(&data);
  if (infos->path_file != NULL && docs.actif->path_file != NULL)
    {
      data.fichier = fopen (docs.actif->path_file, "w");
      if (data.fichier)
        {
          data.p_text_buffer = gtk_text_view_get_buffer (docs.actif->p_text_view);
          gtk_text_buffer_get_bounds (data.p_text_buffer, &data.start, &data.end);
          data.contents = gtk_text_buffer_get_text (data.p_text_buffer,
						    &data.start, &data.end, FALSE);
          data.locale = g_locale_from_utf8 (data.contents, -1, NULL, NULL, NULL);
          g_free (data.contents), data.contents = NULL;
          fprintf (data.fichier, "%s", data.locale);
          g_free (data.locale), data.locale = NULL;
          fclose (data.fichier), data.fichier = NULL;
          docs.actif->sauve = TRUE;
        }
      else
        fprintf(stderr, "Error open\n");
    }
}
