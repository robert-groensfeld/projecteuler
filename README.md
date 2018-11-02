# Project Euler

Solutions to some mathematical problems from 
[Project Euler](https://projecteuler.net/) that I found on my disk.

## Build

After installing [CMake](https://cmake.org/), run these commands in the project
directory:

```bash
mkdir -p build && cd build && cmake .. && make && cd ..
```

The solution programs will be located in `build/bin`.

## View Haskell Solutions

Install the [Glasgow Haskell Compiler](https://www.haskell.org/ghc/). You should
now be able to start the interactive environment by executing `ghci`. Assuming
you are in the project directory, load a solution file with 
`:load haskell/29.hs`. Replace `29.hs` with the filename of the solution.

Now you can call functions from the solution file, e.g. `permutations 4 7`.

Exit with `:quit`.

## Test

Build the project, then run `./build/bin/projecteuler-test`.