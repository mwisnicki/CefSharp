@echo off
echo Refreshing to: Chromium %CHROMIUM_VERSION% rev %CHROMIUM_REVISION%
timeout 5
If exist chromium ( echo Chromium directory exists. && cd chromium ) ELSE ( mkdir chromium && echo Chromium directory created. && cd chromium)
call gclient config http://src.chromium.org/svn/trunk/src
copy ..\tools_cfg\.gclient .
rmdir /S /Q %TOOLDIR%\depot_tools\svn_bin
mkdir %TOOLDIR%\depot_tools\svn_bin
copy /Y %TOOLDIR%\svn %TOOLDIR%\depot_tools\svn_bin\
call svn ls http://src.chromium.org/chrome
call gclient sync --revision src@%CHROMIUM_REVISION% --jobs 8 --force
call gclient runhooks
cd %DEVDIR%
echo Refreshed to: Chromium %CHROMIUM_VERSION% rev %CHROMIUM_REVISION%
