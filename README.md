EaRing: It All Started As A Joke

*NOTICE:* This is only on github as a kind of historical record.  It hasn't been touched since about 2008 and so probably would need some serious updating to be useful.  It will probably not build without some work on your part, and I don't have time.

WELCOME

This is a small project I tinkered on in my spare time as a joke for the
RubyEnRails 2008 conference.  You can read all about the joke at:

  http://zedshaw.com/conferences/rubyenrails2008/

Which includes the presentation I gave.  It was a riot, but the project actually
became fun to just work on in its own right.

You'll find many similarities between EaRing and LLVM, except EaRing has fewer
features, is kind of weird, run on fewer platforms, and is tiny by comparison.

I wouldn't recommend using it in anything serious right now, but it is fun to
check it out and see how it was built.

WHAT IS IT?

EaRing is a dynamic assembler, think of it as a scripting language that uses a
generic CPU-neutral assembly language as the script.  It actually does compile
your script on the fly to assembler for your platform, so it run at the speed of
your CPU.

The important thing about EaRing is that it builds everything on the fly very
fast, and then provides a simple data structure you can use to run the code,
disassemble it, examine the results, etc.  Because everything that get generated
is held in data structures there's also some things that EaRing can do other
assemblers can't:

* You can swap the contents of functions or alter them as if they were data.
* You can plug in any memory management you need.
* It can open dynamic libraries and run the functions like they are another module.
* You can ship the code to other machines and they'll just run it.
* It's still fast because, after the first compile, it run at CPU speed.

I would consider EaRing a tool for learning assembler and not really something
you'd do a full blown language on.  That's what I plan on using it for in the
future.


FEATURES

* Simple API with good examples. Look at earing.c
* Embeddable into your programs (there are no global variables).
* Simple syntax using a real LR parser with good error messages.
* Interactive REPL and you can make it a #! script too.  Yeah, that's weird.
* Constants defined in the assembler are actually not constant.
* Ability to load .so libs and other .asm files and treat them the same.
* You can combine modules as long as the functions don't clash.
* Valgrind pure, so it doesn't leak (except for dlopen and readline's leaks).
* Fast data structures for handling names based on a Ternary Search Tree.
* Written for educational purposes, so the code is easy to read (although not commented yet).
* Uses GNU lightning so runs on a few processors, not tested though.
* Actually works, which is kind of amazing.
* The ability to compile your modules, and then disassemble them to the real x86 bytecodes being used.


PLATFORMS

Since this is an initial release, I only really got it to work on a few
platforms, but it should run on others:

* Linux x86-64 AMD.
* Mac OSX x86-32 Intel.  Disassembly probably won't work here.


LICENSE

Right now I don't have a license on it since I've got no idea if anyone will use
it.  Just consider it free to use for educational purposes, and contact me if
you have any ideas about the license.


INSTALLATION

Quick instructions for trying out Earing.  Currently it works great on Linux x86-64
and probably on other Linux, but shoot me feedback.

You need to have a recent version of Python 2.5 installed:

1. Grab the tarball from the website: http://zedshaw.com/projects/earing
1. python software/ez_setup.py  (only do this if you don't have easy_install already)
2. easy_install zapps pygments idiopidae vellum
4. tar -xjvf earing-VERSION.tar.bz2
5. cd earing-VERSION
6. vellum software-64  (on non-64bit do: vellum software-others)
7. vellum build (OSX do: build-OSX)
9. build/earing samples/linux-64.asm (build/earing samples/osx-32.asm on OSX)
10. build/earing -h
11. build/earing -i samples/linux-64.asm

Have fun.  The big sample script is in samples/simpler.asm and has tons of
simple little functions showing off the features.

If you don't have Python you can still install it, but you'll have to figure it
out yourself.  Look at build.vel and software/build.vel for the automation.

There's a bug in how double/float types are handled on 32-bit vs. 64-bit.  Still
have to track it down, but you can't use float on 64-bit, and can't use double
on 32-bit.  I probably have to change the size of the values in tokens.  Anyway,
look at the osx-32.asm to see how libraries are loaded, and check out its main
to see how to do float calls to library functions.  Look at linux-64.asm for the
inverse example.

There was readline support, but readline behaves differently between Linux and
OSX so I removed it until I can learn more about it.


CONTRIBUTING

I have to work on a book for the next month or so, which means I won't be doing
too much with this project until then.  If you're interested in working on it,
here's what I suggest:

1. I have the Bazaar repository at http://zedshaw.com/repository/earing
2. Make a branch and start your hacking.
3. As you have interesting patches or bug fixes, email them to me at
    zedshaw@zedshaw.com or tell me where your branch is online.
4. I'll periodically do releases that include other people's stuff.

If people start contributing then I'll pick an open source license.  Otherwise,
enjoy the hack and the joke.


