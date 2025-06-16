# UIA language

I has just writen it for fun :)))

U can use changeEverythingToUIA.cpp to normal cpp file and it change to UIA version.

But it now can't completely remove all characters other than uia like:
- number with 2 or more character 
  - can use it like abcd = iiii(a1 b1 c1 d1)
  - example: iiii(I U a u i Aa Au Ai Ia A) mean 1234567890
  - it can compile and run fine but in editor it show as error.
  - You can try: UiaCompiler/UiaRun test_xu_ly_con_so.uia to see it can be run but show error on editor.

## How to use it???

1. Clone this project

2. In root folder of this project UIA/ here is how to run:

- Run convert cpp -> uia
UiaCompiler\changeToUIA path/file_need_to_convert.cpp

- Run file:
UiaCompiler\UiaRun path/file_to_run.uia


- Example:
UiaCompiler\UiaRun helloworld.uia

## How to use compiler and build tools:

Setup in vscode:

1. You need install all enviroment for cpp (as GNU)
2. Install Cmake https://cmake.org/download/
3. Install Cmake extension for VsCode: ms-vscode.cmake-tools
4. F1 > Cmake: Configure to run again (if it not autoload from .vscode and build folder)
5. Edit and make code (It make a bit error for cpp file to show when you use word in UiaCompiler/uia_char_def.h, as a, i,... just chang to a1, i1,...)