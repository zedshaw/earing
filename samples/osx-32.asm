%library("libm.dylib", "math")
%library("libc.dylib", "libc")
%import("samples/imported.asm", "imported")
# this changes the default code size just before we start the next function
# we can call it at any time before a function to change its code size
%code_size(200)


# these are part of this module, you can also have them in a function
MY_NAME = "Zed A. Shaw, INTERNET ANGRY MAN"
MY_AGE = 1200
MY_INITIAL = 'A'



function puts_sample() : int
    # this one is part of a function
    another_name = "Joe Blow"

    # prints a simple string with puts
    movi.p(R0, another_name)
    prepare.i(1)
    pusharg.p(R0)
    finish(libc.puts)

    # this is a global that we've set
    movi.p(R0, MY_NAME)
    prepare.i(1)
    pusharg.p(R0)
    finish(libc.puts)
end

# Ok, this is just fucking weird, but could be cool as hell when coroutines are in.
# You can access the constants that other functions declare.
function data_sharing_test() : int
    movi.p(R0, self.puts_sample.another_name)
    prepare.i(1)
    pusharg.p(R0)
    finish(libc.puts)
end

%leaf 
function test1() : int
    movi.i(R1, 10000)
    movi.i(R0, 20)

    mulr.i(RET, R1, R0)
end

%leaf
function test2(): int
    movi.i(RET, 100)
end



function malloc_test() : void
    movi.ui(R0, 1024)
    prepare.i(1)
    pusharg.ui(R0)
    finish(libc.malloc)
    movr.ui(R0, RET)

    prepare.i(1)
    pusharg.ui(R0)
    finish(libc.free)
end

# yes, this replaces the code in test1 with test2 and calls it
function make_test1_test2() : int
    movi.ui(R1, 0)

next:
    ldxi.c(R0, R1, self.test2)
    stxi.c(self.test1, R1, R0)
    addi.ui(R1, R1, 1)
    blti.ui(next:, R1, 21)

    calli(self.test1)
end

%leaf
function incrementer() : int
    movi.i(R0, 0)

again:
    addi.i(R1, R0, 1)
    movr.i(R0, R1)
    
    blti.i(again:, R0, 10)

    movr.i(RET, R0)
end

%leaf
function reflect(in : uint) : uint
    getarg.ui(RET, in)
end

%leaf
function fibit(in : ulong) : ulong
    getarg.ul(R2, in)
    movi.ul(R1, 1)

    blti.ul(exit:, R2, 2)

    subi.ul(R2, R2, 1)
    movi.ul(R0, 1)

loop:
    subi.ul(R2, R2, 1)
    addr.ul(V0, R0, R1)
    movr.ul(R0, R1)
    addi.ul(R1, V0, 1)
    bnei.ul(loop:, R2, 0)

exit:
    movr.ul(RET, R1)
end

function fibit_huge_loop() : ulong
    movi.ui(V1, 5000000)

again:
    prepare.i(1)
    movi.ul(R0, 93)
    pusharg.ul(R0)
    finish(self.fibit)
    retval.ul(R0)

    # decrement and repeat
    subi.ui(V1, V1, 1)
    bgti.ui(again:, V1, 0)

    # grab the last value as a check
    movr.ul(RET, R0)
end

function print_fibit10() : ulong
    prepare.i(1)
    movi.ul(R0, 93)
    pusharg.ul(R0)
    finish(self.fibit)
# can also just be returned right away since RET already has it
    retval.ul(R0)
    movr.ul(RET, R0)
end


function print_reflect() : uint
    prepare.i(1)
    movi.ui(R0, 93)
    pusharg.ui(R0)
    finish(self.reflect)
    # since we return right away we don't need to do the retval/movr
end


function nfibs(in : uint) : uint
    getarg.ui(V0, in)      # V0 = n
                     
    blti.ui(exit:, V0, 2)
    subi.ui(V1, V0, 1)     # V1 = n - 1
    subi.ui(V2, V0, 2)     # V2 = n - 2

    # call first recursion
    prepare.i(1)
    pusharg.ui(V1)         # V1 = nfibs(n-1)
    finish(self.nfibs)
    retval.i(V1)

    # call second recursion
    prepare.i(1)
    pusharg.ui(V2)         # V2 = nfibs(n-2)
    finish(self.nfibs)
    retval.i(V2)

    addi.ui(V1, V1, 1)     # V1++
    addr.ui(RET, V1, V2)   # V1 + V2 + 1

exit:
    movi.i(RET, 1)
end


function print_nfibs10() : uint
    prepare.i(1)
    movi.ui(R0, 10)
    pusharg.ui(R0)
    finish(self.nfibs)
    retval.ui(R0)
    movr.ui(RET, R0)
end

function lots_of_parameters(one : ui, two : ui, three : ui) : void
end


function main() : float
    calli(self.incrementer)
    calli(self.test1)
    calli(self.test2)
    calli(self.make_test1_test2)
    calli(self.test1)
    calli(self.print_reflect)
    calli(self.print_nfibs10)
    calli(self.fibit_huge_loop)
    calli(imported.imported_setup)

    movi.f(R0, 10.0)

    prepare.i(1)
    pusharg.f(R0)
    finish(math.cosf)
    retval.f(R0)

    movr.f(RET, R0)
end

