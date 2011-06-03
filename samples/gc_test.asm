# This is a little EaRing sample file showing the new GC setup I've added.
# It's pretty rough right now, but if I run this file using:
#
#   earing $ build/earing -f forever samples/gc_test.asm > /dev/null
#
# Then it'll loop forever, allocating ram and printing the results, but after
# 2 minutes this is the usage:
#
# 35136 earing      99.3%  1:55.19   1    13     28  388K   184K  1152K    19M
#
# So it's allocating and the GC is working just fine.  Boehm is the man.
#

%library("libc.dylib", "libc")

### these are constants, they stick around for the life of the module, but they're more
### like ASM data regions, meaning you can modify them and shove stuff in them.

# this is a 'constant', but we can modify it
NUMBERS = "01234567890"
# this is a constant for the length
NUMBER_LEN = 11  # includes the \0
# yep, another one
ONE_K_OF_RAM = 1024
# what's this? just a sample showing using the [size] syntax to make a constant blob of ram
A_CHUNK = [ONE_K_OF_RAM]


# This function tests out the new allocator ops by making some ram, reallocing it,
# forcing it freed, forcing the GC to collect, then making and realloc again.  To make
# sure the ram was made, it then copies from NUMBERS into this new ram and printing it
# out.
function allocator_test() : void
    movi.ui(V1, 0)

    # do a bunch of stupid GC operations
    sizeof.i(R2)
    sizeof(R2, NUMBERS)
    alloc(R2, 1024)    # makes 1k, currently have to use a number
    realloc(R2, 1)     # realloc it to 1 byte
    free(R2)           # do a force free (not necessary)
    alloc(R2, 1024)    # allocate some more
    realloc(R2, 30)    # reallocate it to 30 bytes
   
    # now we copy NUMBERS into our new chunk of ram
next:
    ldxi.c(R0, V1, NUMBERS)
    stxr.c(R2, V1, R0)
    addi.ui(V1, V1, 1)
    blti.ui(next:, V1, NUMBER_LEN)

    # and finally, let's print that out
    prepare.i(1)
    pusharg.p(R2)
    finish(libc.puts)
end


# This is a function that just loops forever and runs allocator_test.
# It forces a call to the GC in the loop to test that out.
function forever() : void
again:
    calli(self.allocator_test)
    jmpi(again:)
end

# The main funciton just runs allocator_test 1000 times and exits.  Easy.
function main() : void
    movi.ui(V0, 0)

again:
    calli(self.allocator_test)
    addi.ui(V0, V0, 1)
    blti.ui(again:, V0, 1000)
end
