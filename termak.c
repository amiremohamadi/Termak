/*
 * TERMAK (stupid terminal emulator)
 * Author: @amiremohamadi
 * This is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#include "termak.h"
static int status = EXIT_FAILURE;


void
termak_init(int argc, char **argv)
{
    GtkWidget *window, *widget;
    VteTerminal *termak;

    gtk_init(&argc, &argv);

    // create window to hold the shell
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // create the terminal widget and add it to the window
    widget = vte_terminal_new();
    termak = VTE_TERMINAL(widget);

    gtk_container_add(GTK_CONTAINER(window), widget);

    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };

	vte_terminal_spawn_async(
        termak,
        VTE_PTY_DEFAULT,
        NULL,       /* working directory  */
        command,    /* command */
        NULL,       /* environment */
        0,          /* spawn flags */
        NULL, NULL, /* child setup */
        NULL,       /* child pid */
        -1,         /* timeout */
        NULL, NULL, NULL);

    gtk_widget_show_all(window);
}


int
main(int argc, char **argv)
{
    termak_init(argc, argv);
    gtk_main();
    return status;
}
