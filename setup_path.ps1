# Add UiaCompiler to PowerShell PATH
$UiaCompilerPath = Join-Path $PSScriptRoot "UiaCompiler"
$env:Path += ";$UiaCompilerPath"
Write-Host "Added UiaCompiler to PowerShell PATH"
Write-Host "Now you can run commands like: UiaRun test_xu_ly_con_so.uia"

# Optional: Add to user PATH permanently
$userPath = [Environment]::GetEnvironmentVariable("Path", "User")
if (-not $userPath.Contains($UiaCompilerPath)) {
    [Environment]::SetEnvironmentVariable("Path", "$userPath;$UiaCompilerPath", "User")
    Write-Host "Added UiaCompiler to permanent user PATH"
} 