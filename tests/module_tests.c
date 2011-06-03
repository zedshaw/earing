#include <cut/2.6/cut.h>

/* A pointless module -- tests nothing useful, will never fail.
 * This nonetheless shows the basic form of tests. */

void __CUT__module1( void )
{
   ASSERT( 1, "Any non-zero value must always pass an ASSERT." );
}

/* A more complex test, consisting of a bringup, a takedown,
 * and the test body. */

static int module_broughtup = 0;

void __CUT_BRINGUP__moduleBringup( void )
{
	module_broughtup = 1;
}

void __CUT__module2( void )
{
	/* ASSERT explanations are usually phrased as mandatory statements. */
	ASSERT( 1 == module_broughtup, "We must be initialized by now." );
}

void __CUT_TAKEDOWN__moduleBringup( void )
{
	/* ASSERTs in takedowns are a very bad idea; takedowns have to be able to
	 * run at any time, including when a test has thrown an exception. */
	module_broughtup = 0;
}

void __CUT__module3( void )
{
	ASSERT( 0 == module_broughtup, "We must be uninitialized by now." );
}

