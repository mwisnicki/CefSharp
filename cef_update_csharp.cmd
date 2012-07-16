@echo off
echo Refreshing to: CEF %CEF_VERSION% rev %CEF_REVISION%
timeout 5
cd chromium
cd src
cd cef
cd binary_distrib
cd cef_binary_%CEF_VERSION%.%CHROMIUM_VERSION%.%CEF_REVISION%_windows
rmdir /S /Q %DEVDIR%\include
mkdir %DEVDIR%\include
xcopy /Y /I /E /H include %DEVDIR%\include

rmdir /S /Q %DEVDIR%\libs
mkdir %DEVDIR%\libs
xcopy /Y /I /E /H lib %DEVDIR%\libs

rmdir /S /Q %DEVDIR%\Release
mkdir %DEVDIR%\Release
xcopy /Y /I /E /H Release %DEVDIR%\Release

rmdir /S /Q %DEVDIR%\Debug
mkdir %DEVDIR%\Debug
xcopy /Y /I /E /H Debug %DEVDIR%\Debug

cd %DEVDIR%
copy /Y Release\lib\libcef_dll_wrapper.lib libs\Release
rmdir /S /Q Release\lib
rmdir /S /Q Release\obj

copy /Y Debug\lib\libcef_dll_wrapper.lib libs\Debug
rmdir /S /Q Debug\lib
rmdir /S /Q Debug\obj


echo Refreshed to: CEF %CEF_VERSION% rev %CEF_REVISION%
