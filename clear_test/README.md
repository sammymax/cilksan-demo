# clear_test

This program, when compiled with Cilksan enabled, **should not show any races**.
It invokes the same function (`test_func`) twice. This function allocates a
local array, does some math on the array, then returns the result.

This test aims to ensure that Cilksan clears the shadow memory properly. Upon
exit of a function, Cilksan clears the shadow memory corresponding to that
function's stack. This is needed because otherwise, later functions that use
the same portion of the stack would be marked as races. We hope in this test
that if Cilksan doesn't clear the shadow memory properly, then the second
call to `test_func` will trigger a race, indicating a problem with Cilksan.
