/*
 *      This file is part of GPaste.
 *
 *      Copyright 2013 Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
 *
 *      GPaste is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      GPaste is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with GPaste.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gpaste-sync-primary-to-clipboard-keybinding-private.h"
#include "gpaste-settings-keys.h"

G_DEFINE_TYPE (GPasteSyncPrimaryToClipboardKeybinding, g_paste_sync_primary_to_clipboard_keybinding, G_PASTE_TYPE_KEYBINDING)

static void
g_paste_sync_primary_to_clipboard_keybinding_class_init (GPasteSyncPrimaryToClipboardKeybindingClass *klass G_GNUC_UNUSED)
{
}

static void
g_paste_sync_primary_to_clipboard_keybinding_init (GPasteSyncPrimaryToClipboardKeybinding *self G_GNUC_UNUSED)
{
}

static void
g_paste_sync_primary_to_clipboard_keybinding_sync (GPasteClipboardsManager *gcm)
{
    g_paste_clipboards_manager_sync_from_to (gcm,
                                             GDK_SELECTION_PRIMARY,
                                             GDK_SELECTION_CLIPBOARD);
}

/**
 * g_paste_sync_primary_to_clipboard_keybinding_new:
 * @settings: a #GPasteSettings instance
 * @gcm: a #GPasteClipboardManager instance
 *
 * Create a new instance of #GPasteSyncPrimaryToClipboardKeybinding
 *
 * Returns: a newly allocated #GPasteSyncPrimaryToClipboardKeybinding
 *          free it with g_object_unref
 */
G_PASTE_VISIBLE GPasteKeybinding *
g_paste_sync_primary_to_clipboard_keybinding_new (GPasteSettings          *settings,
                                                  GPasteClipboardsManager *gcm)
{
    g_return_val_if_fail (G_PASTE_IS_SETTINGS (settings), NULL);
    g_return_val_if_fail (G_PASTE_IS_CLIPBOARDS_MANAGER (gcm), NULL);

    return _g_paste_keybinding_new (G_PASTE_TYPE_SYNC_PRIMARY_TO_CLIPBOARD_KEYBINDING,
                                    settings,
                                    SYNC_PRIMARY_TO_CLIPBOARD_KEY,
                                    g_paste_settings_get_sync_primary_to_clipboard,
                                    (GPasteKeybindingFunc) g_paste_sync_primary_to_clipboard_keybinding_sync,
                                    gcm);
}
