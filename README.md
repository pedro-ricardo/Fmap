# Mapping in Modern Fortran
Simple dictionary that maps `string` to `1D array` in Modern Fortran.

* This code just uses the C++ `std::map` from Modern Fortran,
it doesn't need any algorithm in Fortran.
* Free from memory leaks
* The purpose of this repo is to show that it is possible to do this fairly easy.
Please edit the files to fit your needs.

## Tested With:
| Library  | Version  |
| -------- | -------- |
| GCC      | 10.2.1   |
| Valgrind | 3.15.0   |
