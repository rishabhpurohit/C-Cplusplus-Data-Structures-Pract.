$Object Files

When you compile a project with g++, g++ actually performs several distinct tasks:

    The preprocessor runs and executes any statement beginning with a hash symbol: #, such as #include statements. This ensures all code is in the correct location and ready to compile.
    Each file in the source code is compiled into an "object file" (a .o file). Object files are platform-specific machine code that will be used to create an executable.
    The object files are "linked" together to make a single executable. In the examples you have seen so far, this executable is a.out, but you can specify whatever name you want.

It is possible to have g++ perform each of the steps separately by using the -c flag. For example,

g++ -c main.cpp

will produce a main.o file, and that file can be converted to an executable with

g++ main.o


# Compiling One File of Many, Step 1

In the previous example, you compiled a single source code file to an object file, and that object file was then converted into an executable.

Now you are going to try the same process with multiple files. Navigate to the multiple_files_example directory in the terminal to the right. This directory should have the increment_and_sum and vect_add_one files from a previous Notebook. Try compiling with the commands below:

root@abc123defg:/home/workspace/multiple_files_example# g++ -c *.cpp
root@abc123defg:/home/workspace/multiple_files_example# g++ *.o
root@abc123defg:/home/workspace/multiple_files_example# ./a.out

Here, the * operator is a wildcard, so any matching file is selected. If you compile and run these files together, the executable should print:

    The total is: 14
