/* unit test for the GFinder implementation */

#include "g-finder.h"

int
main (int argc, char* argv[])
{
	GFinder *finder;

	g_type_init ();

	finder = g_finder_new ();

/* do something interesting with our brand new object */
    g_finder_do_something (finder, "Hello World");

	return 0;
}
