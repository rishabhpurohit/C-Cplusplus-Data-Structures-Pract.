# Object Files

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


# Compiling One File of Many, Step 2

But what if you make changes to your code and you need to re-compile? In that case, you can compile only the file that you changed, and you can use the existing object files from the unchanged source files for linking.

Try changing the code in /multiple_files_example/main.cpp to have different numbers in the vector and save the file with CTRL-s.

When you have done that, re-compile just main.cpp by running:

root@abc123defg:/home/workspace/multiple_files_example# g++ -c main.cpp
root@abc123defg:/home/workspace/multiple_files_example# g++ *.o
root@abc123defg:/home/workspace/multiple_files_example# ./a.out

Compiling just the file you have changed saves time if there are many files and compilation takes a long time. However, the process above is tedious when using many files, especially if you don't remember which ones you have modified.

For larger projects, it is helpful to use a build system which can compile exactly the right files for you and take care of linking. 

# CMake and Make

CMake is an open-source, platform-independent build system. CMake uses text documents, denoted as CMakeLists.txt files, to manage build environments, like make. A comprehensive tutorial on CMake would require an entire course, but you can learn the basics of CMake here, so you'll be ready to use it in the upcoming projects.
CMakeLists.txt

CMakeList.txt files are simple text configuration files that tell CMake how to build your project. There can be multiple CMakeLists.txt files in a project. In fact, one CMakeList.txt file can be included in each directory of the project, indicating how the files in that directory should be built.

These files can be used to specify the locations of necessary packages, set build flags and environment variables, specify build target names and locations, and other actions.

In the next few pages of this workspace, you are going to create a basic CMakeLists.txt file to build a small project.

# CMake Step 1

In the terminal to the right, navigate to the cmake_example folder. This folder should contain a simple CMake project, including:

    An empty CMakeLists.txt file
    A src directory with the increment_and_sum and vect_add_one files from a previous Notebook

The CMakeLists.txt file should be open in the tabs on the right, along with the files from the src directory. You will write a basic CMakeLists.txt file to build all of these project files into an executable.

The first lines that you'll want in your CMakeLists.txt are lines that specifies the minimum versions of cmake and C++ required to build the project. Add the following lines to your CMakeLists.txt and save the file:

cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)

These lines set the minimum cmake version required to 3.5.1 and set the environment variable CMAKE_CXX_STANDARD so CMake uses C++ 14. On your own computer, if you have a recent g++ compiler, you could use C++ 17 instead.

# CMake Step 2

CMake requires that we name the project, so you should choose a name for the project and then add the following line to CMakeLists.txt:

project(<your_project_name>)

You can choose any name you want, but be sure to change <your_project_name> to the actual name of the project!

# CMake Step 3

Next, we want to add an executable to this project. You can do that with the add_executable command by specifying the executable name, along with the locations of all the source files that you will need. CMake has the ability to automatically find source files in a directory, but for now, you can just specify each file needed:

add_executable(your_executable_name  path_to_file_1  path_to_file_2 ...)

Hint: The source files you need are the three .cpp files in the src/ directory. You can specify the path relative to the CMakeLists.txt file, so src/main.cpp would work, for example.

# CMake Step 4

A typical CMake project will have a build directory in the same place as the top-level CMakeLists.txt. Make a build directory in the /home/workspace/cmake_example folder:

root@abc123defg:/home/workspace/cmake_example# mkdir build
root@abc123defg:/home/workspace/cmake_example# cd build

From within the build directory, you can now run CMake as follows:

root@abc123defg:/home/workspace/cmake_example/build# cmake ..
root@abc123defg:/home/workspace/cmake_example/build# make

The first line directs the cmake command at the top-level CMakeLists.txt file with ... This command uses the CMakeLists.txt to configure the project and create a Makefile in the build directory.

In the second line, make finds the Makefile and uses the instructions in the Makefile to build the project.

If CMake and Make are successful, you should see something like the following output in the terminal:

## 50%] Building CXX object CMakeFiles/eg.dir/src/vect_add_one.cpp.o
## [ 75%] Building CXX object CMakeFiles/eg.dir/src/increment_and_sum.cpp.o
## [100%] Linking CXX executable eg


# CMake Step 5

If everything has worked correctly, you should now be able to run your executable from the build folder:

root@abc123defg:/home/workspace/cmake_example/build# ./your_executable_name

This executable should print:

    The total is: 14

just as it did in the previous workspace.

If you don't remember the name of your executable, the last line of the make output should tell you:

[100%] Built target <your_executable_name>
