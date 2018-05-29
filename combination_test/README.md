# combination_test

`record_mem_helper` in `cilksan.cpp` calls various helper functions
in the shadow dictionary. The exact functions it calls depends on:
1. whether this address has been read before
2. whether this address has been written to
3. whether the current access is a read or write

This test checks all 8 cases. If you want to check a specific case,
pass it in as an argument to the program (see source for how).
Among all 8 cases, **this code should generate six races**. Cilksan
currently displays this as 3 races and 3 duplicates.

This test actually goes through 16 combinations, because for each
of the 8 cases above, it does one run with the "previous" read in
parallel with the current access, and one with the "previous" write
in parallel with the current access. Previous in quotations because
they are in parallel, but one appears earlier in the source code.

For example, in the case where both r+w exist in the shadow memory
already, and we do another write, this program checks two cases:
* read, then write + write in parallel
* write, then read + write in parallel

The six races outputted should come from:
1. _wr, writes in parallel
2. _ww, writes in parallel
3. r_w, reads in parallel
4. rwr, writes in parallel
5. rww, reads in parallel
6. rww, writes in parallel
