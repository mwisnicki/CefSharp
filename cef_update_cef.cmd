@echo off
echo Refreshing to: CEF %CEF_VERSION% rev %CEF_REVISION%
timeout 5
cd chromium
cd src
rmdir /S /Q cef
call svn co -r %CEF_REVISION% http://chromiumembedded.googlecode.com/svn/trunk/cef%CEF_VERSION% cef
cd cef
call cef_create_projects.bat
cd %DEVDIR%
echo Refreshed to: CEF %CEF_VERSION% rev %CEF_REVISION%
