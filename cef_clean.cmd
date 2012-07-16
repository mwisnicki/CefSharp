@echo off
echo Cleaning code: Chromium %CHROMIUM_VERSION% rev %CHROMIUM_REVISION%, CEF %CEF_VERSION% rev %CEF_REVISION%
timeout 5
del /f /s /q %DEVDIR%\chromium
rmdir /s /q %DEVDIR%\chromium
echo Cleaned code: Chromium %CHROMIUM_VERSION% rev %CHROMIUM_REVISION%, CEF %CEF_VERSION% rev %CEF_REVISION%