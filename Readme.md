# UIA language

I has just writen it for fun :)))

U can use changeEverythingToUIA.cpp to normal cpp file and it change to UIA version.

But it now can't completely remove all characters other than uia like:
- number with 2 or more character 
  - can use it like abcd = iiii(a1 b1 c1 d1)
  - example: iiii(I U a u i Aa Au Ai Ia A) mean 1234567890
  - it can compile and run fine but in editor it show as error.
  - You can try: UiaCompiler/UiaRun test_xu_ly_con_so.uia to see it can be run but show error on editor.


- In root folder of this project UIA/ here is how to run:

- Run convert cpp -> uia
UiaCompiler/changeToUIA file_need_to_convert.cpp

- Run file:
UiaCompiler/UiaRun file_to_run.uia

