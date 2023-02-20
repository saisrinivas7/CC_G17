#def abc bd
#def MACRO let x = 1; \
dbg x;

#def AA 10

let abc = 123 * 45 + 5 + (10 / 2) - AA;
dbg abc + abc;

// a single line comment
/* a multi line comment */


#undef abc
let abc = 2;
MACRO


#ifdef DEBUG
dbg x;
#endif

#ifdef DEBUG2
dbg y;
#elif DEBUG3
dbg 2*y;

#else DEBUG4
dbg 3*y;
#endif
