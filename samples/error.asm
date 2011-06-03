function badoptype : v
    movi.blah(R0,R1)
end

function badfunctype : not
    movi.ui(R0,1)
end

function unterminated : v


function recovers : v

end

function badtokens : i
    movi.ui($$,$$)
end

function notbad : v
    movi.ui(RET, 1)
    ret
end
