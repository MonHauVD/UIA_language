cd UiaCompiler
g++ -o uia_compiler uia_main.cpp uia_preprocessor.cpp uia_compiler.cpp

g++ UiaCompiler/uia_run.cpp -o UiaRun

-chạy file không có dấU cách
UiaCompiler/UiaRun uia.uia

- chạy file có dấU cách
UiaCompiler/UiaRun "test co cach.uia"

- test dấu nháy kép
UiaCompiler/UiaRun test_xu_ly_dau_nhay_kep.uia