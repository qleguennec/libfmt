# libfmt
Simplified printf implementation with libvect integration.

Final version will include:
- _%s_ copy a null-terminated string
- _%v_ copy the used part of a vector
- _%{[-]b/n}_ copy n bytes in base b from argument, interpreted as signed if '-' is included

Example from printf usual format conversions:
- _%d_ for %-10/4
- _%u_ for %10/4
