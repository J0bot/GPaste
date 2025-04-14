/*
 * This file is part of GPaste.
 *
 * Copyright (c) 2010-2022, Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
 */

#include <gpaste-gtk4/gpaste-gtk-preferences-dialog.h>
#include <gpaste-gtk4/gpaste-gtk-util.h>

static void
quit_activated (GSimpleAction *action    G_GNUC_UNUSED,
                GVariant      *parameter G_GNUC_UNUSED,
                gpointer       user_data)
{
    g_application_quit (G_APPLICATION (user_data));
}

gint
main (gint argc, gchar *argv[])
{
    G_PASTE_GTK_INIT_APPLICATION ("Preferences");

    GActionEntry app_entries[] = {
        { "quit",   quit_activated,   NULL, NULL, NULL, { 0 } },
    };

    g_action_map_add_action_entries (G_ACTION_MAP (app), app_entries, G_N_ELEMENTS (app_entries), app);

    AdwDialog *dialog = g_paste_gtk_preferences_dialog_new (gapp);

    adw_dialog_present (dialog, NULL);

    return g_application_run (gapp, argc, argv);
}
