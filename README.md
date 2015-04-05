# CSC3022H - Assignment 3 - Text Compression and Catch Unit Testing

Jethro Muller  
5 April 2015

----

# Instructions

#### Running the compression

1. Navigate to the project root directory `assignment-3`.
2. Run `make` to build the executable, `huffencode` in the `build` directory.
3. Run `make run ARGS="<input_file> <output_file>"` to run `huffencode` with the given input and output names.  
   NB: These files should be in the `build` directory.
4. Run `make clean` to delete any artifacts created when compiling & running the compression program.

#### Running the Unit Tests

1. Navigate to the project root directory `assignment-3`.
2. Run `make tests` to build the executable, `test` in the `build/Tests` directory.
3. Run `make run-tests` to run the `test` executable.
4. Run `make clean` to delete any artifacts created when running the tests.
