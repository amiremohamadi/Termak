#include <vte.h>

struct config {
	gchar *config_file;
	gchar *font;
	gint lines;
	gchar *role;
	gboolean bold;
	GdkRGBA background;
	GdkRGBA foreground;
	GdkRGBA highlight;
	GdkRGBA highlight_fg;
	GdkRGBA palette[16];
	gsize palette_size;
};
