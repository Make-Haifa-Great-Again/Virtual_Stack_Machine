# comments ....
        PUSH 100
        PUSHIP $L12   # prepare return address
        PUSHIP   $mul_6  # prep destination address
        POPIP         # call that function
$L12:   PUSH 12
        PUSHIP   $SUM   #
        PUSHIP   $mul_6
        POPIP
$SUM:    ADD
        HLT
$mul_6:
        DUP
        DUP
        DUP
        DUP
        DUP
        ADD
        ADD
        ADD
        ADD
        ADD
        POPIP
        HLT