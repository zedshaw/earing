EaRing: It All Started As A Joke
================================

*NOTICE:* This is only on github as a kind of historical record.  It hasn't been touched since about 2008 and so probably would need some serious updating to be useful.  It will probably not build without some work on your part, and I don't have time.

WELCOME
=======

This is a small project I tinkered on in my spare time as a joke for the
RubyEnRails 2008 conference.  It was a riot, but the project actually became
fun to just work on in its own right.

You'll find many similarities between EaRing and LLVM, except EaRing has fewer
features, is kind of weird, run on fewer platforms, and is tiny by comparison.

I wouldn't recommend using it in anything serious right now, but it is fun to
check it out and see how it was built.

WHAT IS IT?
===========

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
========

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
=========

Since this is an initial release, I only really got it to work on a few
platforms, but it should run on others:

* Linux x86-64 AMD.
* Mac OSX x86-32 Intel.  Disassembly probably won't work here.


LICENSE
=======

Copyright (c) 2008, Zed A. Shaw
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
must display the following acknowledgement:
This product includes software developed by the <organization>.
4. Neither the name of the <organization> nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY ZED A. SHAW ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


INSTALLATION
============

Don't bother, it's bitrot by now so you'd have to work on it.

There's a bug in how double/float types are handled on 32-bit vs. 64-bit.  Still
have to track it down, but you can't use float on 64-bit, and can't use double
on 32-bit.  I probably have to change the size of the values in tokens.  Anyway,
look at the osx-32.asm to see how libraries are loaded, and check out its main
to see how to do float calls to library functions.  Look at linux-64.asm for the
inverse example.

There was readline support, but readline behaves differently between Linux and
OSX so I removed it until I can learn more about it.


CONTRIBUTING
============

If you do pull requests I'll include them, otherwise, this is just a historical
record.


