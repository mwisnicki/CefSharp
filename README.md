# CefSharp - Embedded Chromium for .Net

This project contains .Net CLR bindings for The [Chromium Embedded Framework (CEF)](http://code.google.com/p/chromiumembedded/ "Google Code") by Marshall A. Greenblatt. The bindings are written in C++/CLI but can be used from any CLR language e.g. C# or VB. CefSharp provides both WinForms and WPF web browser control implementations. See the CefSharp.WinForms.Example or CefSharp.Wpf.Example projects for example web browsers built using this library.

This project is [BSD](http://www.opensource.org/licenses/bsd-license.php "BSD License") licensed.

# Binary Release

The /Release directory of this repo contains the CEF and [CefSharp](https://github.com/carloslozano/CefSharp) binaries. Debug versions are not available on the repo itself to save on space. If you need them, please let [me](https://github.com/carloslozano) know and I'll share them with you.

# Contact

Please use the [CefSharp Google Group](https://groups.google.com/forum/#!forum/cefsharp) for discussions of CefSharp usage. There are several forks of CefSharp, please clearly identify VS2010 version if referring to this one.

# Fork

- Initially, the aim of this fork is to update [CefSharp](https://github.com/carloslozano/CefSharp) and dependencies to use the VS2010 toolsets on Windoze.
- Create Mono versions on latest available frameworks on MacOSX and Linux.
- Focus will be on CefSharp.dll and CEF binaries and not on specific uses or demos of the library.

# Changes
---------------------------------------
#### v1.1180.724.0 - *July 16, 2012, Chromium 21.1180.724
- Compiled new CEF1 libraries to Chromium release 1180 and CEF revision 724.
- Migrated projects to VS2010/.NET 4.0, compiled, linked and working (despite M$ library inferno).
- Adopted new versioning scheme to clearly show Chromium release, CEF type and revision and local revision number.

---------------------------------------
#### v0.12 - *July 3, 2012, Chromium 21.1180.711*
- Refreshed the repo and made some time available for coding... I'm getting there! I have a day job! :P

---------------------------------------