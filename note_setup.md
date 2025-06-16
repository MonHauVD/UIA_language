# Setup Instructions

## Quick Start for VS Code (PowerShell)
1. Open VS Code terminal (Terminal > New Terminal)
2. Run PowerShell script:
   ```powershell
   .\setup_path.ps1
   ```
3. Now you can run commands directly:
   ```powershell
   UiaRun test_xu_ly_con_so.uia
   changeToUIA test_xu_ly_con_so.cpp
   ```

## Quick Start for CMD
1. Run `setup_path.bat` to add UiaCompiler to PATH
2. Now you can run commands directly:
   ```
   UiaRun test_xu_ly_con_so.uia
   changeToUIA test_xu_ly_con_so.cpp
   ```

## Manual Setup
If you want to add UiaCompiler to PATH permanently:

1. Open System Properties (Win + Pause/Break)
2. Click "Advanced system settings"
3. Click "Environment Variables"
4. Under "System variables", find and select "Path"
5. Click "Edit"
6. Click "New"
7. Add the full path to your UiaCompiler folder (e.g., D:\Lap trinh\UIA\UiaCompiler)
8. Click "OK" on all windows

After setup, you can run commands directly without specifying the UiaCompiler folder:
```
UiaRun test_xu_ly_con_so.uia
changeToUIA test_xu_ly_con_so.cpp
```

## Troubleshooting

### VS Code PowerShell Issues
If you get "command not found" error in VS Code PowerShell:
1. Make sure you're in the correct directory (where setup_path.ps1 is located)
2. Run the PowerShell script again:
   ```powershell
   .\setup_path.ps1
   ```
3. If still not working, try running PowerShell as Administrator and add to permanent PATH:
   ```powershell
   [Environment]::SetEnvironmentVariable("Path", $env:Path + ";D:\Lap trinh\UIA\UiaCompiler", "User")
   ```
4. Close and reopen VS Code

### CMD Issues
If commands don't work in CMD:
1. Run `setup_path.bat` again
2. Make sure you're in the correct directory
3. Try opening a new CMD window

## Available Commands
- `UiaRun <file.uia>` - Run a UIA file
- `changeToUIA <file.cpp>` - Convert a C++ file to UIA format

## Notes
- The PATH setting is temporary for the current terminal session
- You need to run setup script again when opening a new terminal
- For permanent setup, use the Manual Setup method

- Gen lại file uia_compiler
cd UiaCompiler
g++ -o uia_compiler uia_main.cpp uia_preprocessor.cpp uia_compiler.cpp

- Gen lại file UiaRun
cd UiaCompiler
g++ UiaCompiler/uia_run.cpp -o UiaRun

- Gen lại file changeToUIA
cd UiaCompiler
g++ changeEverythingToUIA.cpp -o changeToUIA


- Về thư mục gốc UIA/ để chạy các file

-chạy file không có dấU cách
UiaCompiler/UiaRun uia.uia

- chạy file có dấU cách
UiaCompiler/UiaRun "test co cach.uia"

- test dấu nháy kép
UiaCompiler/UiaRun test_xu_ly_dau_nhay_kep.uia

- test con số
UiaCompiler/UiaRun test_xu_ly_con_so.uia

- Chạy chuyển đổi cpp -> uia
UiaCompiler/changeToUIA helloworld.cpp