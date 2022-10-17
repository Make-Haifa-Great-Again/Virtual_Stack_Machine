#include "spam.h"

namespace svm {

#define OpCodeT_HOG(_)\
    _(NOP, 0)    /* do nothing */\
    _(ADD, 1)    /* pop a, pop b, push a + b */\
    _(SUB, 2)    /* pop a, pop b, push a - b */\
    _(AND, 3)    /* pop a, pop b, push a & b */\
    _(OR,  4)    /* pop a, pop b, push a | b */\
    _(XOR, 5)    /* pop a, pop b, push a ^ b */\
    _(NOT, 6)    /* pop a, push !a */\
    _(IN,  7)       /* read one char from stdin, push as word on stack (ascii code) */\
    _(OUT, 8)    /* pop one word and write to stream as one char */\
    _(LOAD, 9)    /* pop a, push word read from address a */\
    _(STOR, 10)    /* pop a, pop b, write b to address a */\
    _(JMP, 11)    /* pop a, goto a */\
    _(JZ,  12)    /* pop a, pop b, if a == 0 goto b */\
    _(PUSH, 13)   /* push next word, */\
                   /* if this instruction is at memory address x then push what is in memory address x+1 */\
                              /* and continue with instruction at x+3 */\
    _(DUP, 14)    /* duplicate word on stack */\
    _(SWAP, 15)   /* swap top two words on stack */\
    _(ROL3, 16)   /* rotate top three words on stack once left, (a b c) -> (b c a) */\
    _(OUTNUM, 17) /* pop one word and write to Output as a number */\
    _(INNUM, 18)     /* like IN put treat the input as an integer */\
    _(JNZ, 19)       /* pop a, pop b, if a != 0 goto b */\
    _(DROP, 20)   /* remove top of stack */\
    _(COMPL, 21)  /* pop a, push the complement of a */\
    _(HLT, 22)      /* stop the virtual machine */\
\
    /* Phase Two */\
\
    _(PUSHIP, 23) /* push the content of the memory cell holding the next*/\
                   /* instruction to the IP stack, advance to the next next instruction */\
    _(POPIP, 24)  /* pop IP stack to current IP, effectively performing a jump the address */\
                   /* that was on top if the IP stack */\
    _(DROPIP, 25) /* pop IP, but do not jump */


SPAM(OpCodeT_HOG, OpCodeT)

} // svm