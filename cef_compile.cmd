@echo off
echo Building: CEF %CEF_VERSION%.%CHROMIUM_VERSION%.%CEF_REVISION%
timeout 5
cd chromium\src\cef
call "c:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86
devenv.com /build Debug cef.sln
devenv.com /build Release cef.sln
cd tools
call %DEVDIR%\cef_setenv.cmd
call make_distrib.bat
cd ..
cd binary_distrib
cd cef_binary_%CEF_VERSION%.%CHROMIUM_VERSION%.%CEF_REVISION%_windows
devenv.com /build Release cefclient2010.sln
devenv.com /build Debug cefclient2010.sln
cd %DEVDIR%
echo Built: CEF %CEF_VERSION%.%CHROMIUM_VERSION%.%CEF_REVISION%
