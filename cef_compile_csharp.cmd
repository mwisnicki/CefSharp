@echo off
echo Building: CefSharp %CEF_VERSION%.%CHROMIUM_VERSION%.%CEF_REVISION%
timeout 5
call "c:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86
devenv.com /clean Debug CefSharp.sln
devenv.com /build Debug CefSharp.sln
timeout 5
devenv.com /clean Release CefSharp.sln
devenv.com /build Release CefSharp.sln
cd %DEVDIR%
echo Built: CefSharp %CEF_VERSION%.%CHROMIUM_VERSION%.%CEF_REVISION%
