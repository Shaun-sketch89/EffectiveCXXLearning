# Item29: Understanding the ins and outs of inlining

## Inline idea
Replace each call of function with its code body

## How to define inline
1. The implicit way
* Define a function inside a class definition
* Define a friend function inside a class definition

2. The explicit way
* Precede definition with the inline keyword 

## Where to define inline (check Item25 widget.h/widget_wo_inline.h)
* Inline functions must _typically_ be in header files.
_Most build environments do inlining during compilation. In order to replace a function call with the body of the called function, compilers must know what the function looks like._
* Templates are _typically_ in header files.
_because compilers need to know what a template looks like in order to instantiate it when it’s used._
* _Template instantiation is independent of inlining._

## Inline is a request(hint) to compilers, not a command
Circumstances that compiler will ignore the request
* Too complicated, e.g., those that contain loops or are recursive (Most compilers)
* Calls to virtual functions (All compilers? You can think about why)

## Pros and Cons
### pros.
* Better than macros(Item2 explains in detail)
* Call without having to incur the overhead of a function call

### cons.
* Increase the size of object code
* A reduced instruction cache hit rate