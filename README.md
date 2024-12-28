```
Support_String::x86_64::GNU/Linux::Unix Makefiles
```

## Cane

A programming language for personal learning. Trying to learn more about MSLs and language features.

Non Goals:

1. Performance -> Not worth it for a learning project. I tried going the performant road but the techniques involve lot of indirection that make the development process slow. (See: The nothings lexer page and talks by Chandler Carruth on Carbon's Lexer implementation for how to make things fast/data oriented approaches. The zig compiler internals also discuss interesting ways to speed things up but it does so with a lot of custom machinery.)


### Notes

Currently it looks like:

```
import os;

sum(int32 a, int32 b) {
    ret a + b;
} int32

main() {
    os@print(sum(2, 3));
} int32
```
