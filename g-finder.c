/* g-finder.c */

#include "g-finder.h"
/* include other impl specific header files */

/* 'private'/'protected' functions */
static void g_finder_class_init (GFinderClass *klass);
static void g_finder_init       (GFinder *obj);
static void g_finder_finalize   (GObject *obj);

/* list signals  */
enum {
	/* MY_SIGNAL_1, */
	/* MY_SIGNAL_2, */
	LAST_SIGNAL
};

struct _GFinderPrivate {
	/* private members go here, e.g. */
	gboolean _frobnicate_mode;
};
#define G_FINDER_GET_PRIVATE(o)      (G_TYPE_INSTANCE_GET_PRIVATE((o), \
                                      G_TYPE_FINDER, \
                                      GFinderPrivate))
/* globals */
static GObjectClass *parent_class = NULL;

/* uncomment the following if any signals are defined */
/* static guint signals[LAST_SIGNAL] = {0}; */

G_DEFINE_TYPE (GFinder, g_finder, G_TYPE_OBJECT);

static void
g_finder_class_init (GFinderClass *klass)
{
	GObjectClass *gobject_class;
	gobject_class = (GObjectClass*) klass;

	parent_class            = g_type_class_peek_parent (klass);
	gobject_class->finalize = g_finder_finalize;

	g_type_class_add_private (gobject_class, sizeof(GFinderPrivate));

	/* signal definitions go here, e.g.: */
/*	signals[MY_SIGNAL_1] = */
/*		g_signal_new ("my_signal_1",....); */
/*	signals[MY_SIGNAL_2] = */
/*		g_signal_new ("my_signal_2",....); */
/*	etc. */

    klass->do_action = g_finder_do_something;
}

static void
g_finder_init (GFinder *obj)
{
	obj->_priv = G_FINDER_GET_PRIVATE(obj);

/* to init any of the private data, do e.g: */
	obj->_priv->_frobnicate_mode = FALSE;
}

static void
g_finder_finalize (GObject *obj)
{
/*	free/unref instance resources here */
	G_OBJECT_CLASS(parent_class)->finalize (obj);
}

GFinder*
g_finder_new (void)
{
	return G_FINDER(g_object_new(G_TYPE_FINDER, NULL));
}

/* following: other function implementations */
/* such as g_finder_do_something, or g_finder_has_foo */

void
g_finder_do_something (GFinder *self, const gchar* param)
{
    g_message("GFinder: %s", param);
}


void
g_finder_do_action (GFinder *self, const gchar* param)
{
    g_return_if_fail (G_IS_FINDER (self));

    G_FINDER_GET_CLASS (self)->do_action (self, param);
}
