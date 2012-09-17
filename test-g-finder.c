/* unit test for the GFinder implementation */

#include "g-finder.h"
#include "g-surffinder.h"

int
main (int argc, char* argv[])
{
	GFinder *finder;

	g_type_init ();

	finder = g_finder_new ();

    g_finder_do_something (finder, "I am a finder");

	GSURFFinder *surfFinder;
	surfFinder = g_surffinder_new ();
    g_surffinder_do_something2 (surfFinder, "I am a finder");

    /* inheritance */
    GFinder * upcastedFinder;
    upcastedFinder = G_FINDER(surfFinder);
    g_finder_do_something (upcastedFinder, "I am a finder");

    /* polymorphism */
	GFinder *polyFinder;
	polyFinder = G_FINDER(g_surffinder_new ());
    g_finder_do_action(polyFinder, "I am doing an action");

	return 0;
}
