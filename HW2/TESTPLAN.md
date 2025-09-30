# Program Under Test: `pointer`

## Purpose:
* Verify dynamic memory allocation and pointer operations.
* Ensure program works correctly for different input sizes and avoids segmentation faults.

## Test Cases:
1. Small Allocation
  * Command: `./pointer 16`
  * Expected:
    * Generated string of 15 characters + `\0`.
    * At least 4 integers printed (depending on alignment).

2. Medium Allocation
  * Command: `./pointer 64`
  * Expected:
    * String shows repeating `A-Z1-9`.
    * About 16 integer pairs printed.

3. Large Allocation
  * Command: `./pointer 1024`
  * Expected:
    * String of length 1023 chars (last byte is `\0`).
    * 256 integer pairs printed.

4. Boundary Case: Very Small
  * Command: `./pointer 1`
  * Expected:
    * String is just `\0`.
    * No integer pairs (since < 4 bytes).

5. Boundary Case: Not multiple of sizeof(int)
  * Command: `./pointer 10`
  * Expected:
    * String of 9 chars + `\0`.
    * 2 integer pairs printed (8 bytes). Remaining 2 bytes ignored safely.

## Pass/Fail Criteria:
  * Program does not crash.
  * Output matches expected string pattern.
  * Integer pairs print correctly without memory access violation.