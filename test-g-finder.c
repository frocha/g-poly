/* unit test for the GFinder implementation */

#include "g-finder.h"
#include "g-surffinder.h"

int
main (int argc, char* argv[])
{
	GFinder *finder;

	g_type_init ();

	finder = g_finder_new ();

/* do something interesting with our brand new object */
    g_finder_do_something (finder, "I am a finder");

    /* inheritance */
	GSURFFinder *surfFinder;
	surfFinder = g_surffinder_new ();
    g_surffinder_do_something (surfFinder, "I am a SURF finder");

	return 0;
}
