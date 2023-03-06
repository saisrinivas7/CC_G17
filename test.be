#def abc bd
#def MACRO let x = 1; \
dbg x;

#def AA 10

let abc = 123 * 45 + 5 + (10 / 2) - AA;
dbg abc + abc;

// a single line comment
/* a multi line comment */


#undef abc
let abc = 5;

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

let a = 1;
let b = 6;
let c = 4;

// variable assignment statement
// the following line would give an error had b and c not been declared
a = b + c;

// tests the ternary operator
a = a ? b : c;


