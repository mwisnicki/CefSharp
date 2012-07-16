@echo off
echo Cleaning setup: Chromium %CHROMIUM_VERSION% rev %CHROMIUM_REVISION%, CEF %CEF_VERSION% rev %CEF_REVISION%
timeout 5
del /f /s /q %TOOLDIR%\depot_tools
rmdir /s /q %TOOLDIR%\depot_tools
echo Cleaned setup: Chromium %CHROMIUM_VERSION% rev %CHROMIUM_REVISION%, CEF %CEF_VERSION% rev %CEF_REVISION%