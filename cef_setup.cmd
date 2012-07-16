@echo off
cd %TOOLDIR%
del /S /Q depot_tools.zip
wget --no-check-certificate https://src.chromium.org/svn/trunk/tools/depot_tools.zip
unzip -o depot_tools.zip
del /S /Q depot_tools.zip
cd %DEVDIR%\tools_cfg
if exist %USERPROFILE%\.gyp (echo GYP directory exists.) ELSE (mkdir %USERPROFILE%\.gyp && echo GYP directory created.)
copy include.gypi %USERPROFILE%\.gyp\ /Y
cd %DEVDIR%