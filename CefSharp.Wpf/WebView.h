#pragma once

#include "BrowserSettings.h"
#include "RenderClientAdapter.h"
#include "ScriptCore.h"
    
using namespace Microsoft::Win32::SafeHandles;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Runtime::InteropServices;
using namespace System::Windows;
using namespace System::Windows::Controls;
using namespace System::Windows::Controls::Primitives;
using namespace System::Windows::Input;
using namespace System::Windows::Interop;
using namespace System::Windows::Media;
using namespace System::Windows::Media::Imaging;
using namespace System::Windows::Threading;

namespace CefSharp
{
namespace Wpf
{
    [TemplatePart(Name="PART_Browser", Type=Image::typeid)]
    public ref class WebView : public ContentControl, IRenderWebBrowser
    {
    private:
        delegate void ActionHandler();
        delegate bool MoveFocusHandler(TraversalRequest^ request);

        BrowserSettings^ _settings;

        MCefRefPtr<RenderClientAdapter> _clientAdapter;
        BrowserCore^ _browserCore;
        MCefRefPtr<ScriptCore> _scriptCore;

        Image^ _image;
        ::ToolTip^ _toolTip;
        DispatcherTimer^ _timer;

        int _width, _height;
        InteropBitmap^ _ibitmap;
		HANDLE _fileMappingHandle, _backBufferHandle;
		ActionHandler^ _paintDelegate;

        bool TryGetCefBrowser(CefRefPtr<CefBrowser>& browser);
        void BrowserCore_PropertyChanged(Object^ sender, PropertyChangedEventArgs^ e);
        void Timer_Tick(Object^ sender, EventArgs^ e);
        void ToolTip_Closed(Object^ sender, RoutedEventArgs^ e);
        void SetCursor(SafeFileHandle^ handle);
        void SetTooltipText(String^ text);
        IntPtr SourceHook(IntPtr hWnd, int message, IntPtr wParam, IntPtr lParam, bool% handled);
		void SetBitmap();
        void OnPreviewKey(KeyEventArgs^ e);
        void OnMouseButton(MouseButtonEventArgs^ e);

    protected:
		virtual CefRefPtr<RenderClientAdapter> CreateClientAdapter();
        virtual void Initialize(String^ address, BrowserSettings^ settings);
        virtual Size ArrangeOverride(Size size) override;
        virtual void OnGotFocus(RoutedEventArgs^ e) override;
        virtual void OnLostFocus(RoutedEventArgs^ e) override;
        virtual void OnPreviewKeyDown(KeyEventArgs^ e) override;
        virtual void OnPreviewKeyUp(KeyEventArgs^ e) override;
        virtual void OnMouseMove(MouseEventArgs^ e) override;
        virtual void OnMouseWheel(MouseWheelEventArgs^ e) override;
        virtual void OnMouseDown(MouseButtonEventArgs^ e) override;
        virtual void OnMouseUp(MouseButtonEventArgs^ e) override;
        virtual void OnMouseLeave(MouseEventArgs^ e) override;

    public:
        virtual event PropertyChangedEventHandler^ PropertyChanged
        {
            void add(PropertyChangedEventHandler^ handler)
            {
                _browserCore->PropertyChanged += handler;
            }

            void remove(PropertyChangedEventHandler^ handler)
            {
                _browserCore->PropertyChanged -= handler;
            }
        }

        virtual event ConsoleMessageEventHandler^ ConsoleMessage;

        WebView()
        {
            Initialize(String::Empty, gcnew BrowserSettings);
        }

        WebView(String^ address, BrowserSettings^ settings)
        {
            Initialize(address, settings);
        }

        ~WebView()
        {
            CefRefPtr<CefBrowser> browser;
            if (TryGetCefBrowser(browser))
            {
                browser->CloseBrowser();
            }
        }

        virtual property bool IsBrowserInitialized
        {
            bool get() { return _browserCore->IsBrowserInitialized; }
        }

        virtual property bool IsLoading
        {
            bool get() { return _browserCore->IsLoading; }
        }

        virtual property bool CanGoBack
        { 
            bool get() { return _browserCore->CanGoBack; } 
        }

        virtual property bool CanGoForward
        { 
            bool get() { return _browserCore->CanGoForward; } 
        }

        virtual property int ContentsWidth
        {
            int get() { return _browserCore->ContentsWidth; }
            void set(int contentsWidth) { _browserCore->ContentsWidth = contentsWidth; }
        }

        virtual property int ContentsHeight
        {
            int get() { return _browserCore->ContentsHeight; }
            void set(int contentsHeight) { _browserCore->ContentsHeight = contentsHeight; }
        }

        virtual property String^ Address
        {
            String^ get() { return _browserCore->Address; }
            void set(String^ address) { _browserCore->Address = address; }
        }

        virtual property String^ Title
        {
            String^ get() { return _browserCore->Title; }
            void set(String^ title) { _browserCore->Title = title; }
        }

        virtual property String^ TooltipText
        {
            String^ get() { return _browserCore->TooltipText; }
            void set(String^ text) { _browserCore->TooltipText = text; }
        }

        virtual property IBeforePopup^ BeforePopupHandler
        {
            IBeforePopup^ get() { return _browserCore->BeforePopupHandler; }
            void set(IBeforePopup^ handler) { _browserCore->BeforePopupHandler = handler; }
        }

        virtual property IBeforeBrowse^ BeforeBrowseHandler
        {
            IBeforeBrowse^ get() { return _browserCore->BeforeBrowseHandler; }
            void set(IBeforeBrowse^ handler) { _browserCore->BeforeBrowseHandler = handler; }
        }

        virtual property IBeforeResourceLoad^ BeforeResourceLoadHandler
        {
            IBeforeResourceLoad^ get() { return _browserCore->BeforeResourceLoadHandler; }
            void set(IBeforeResourceLoad^ handler) { _browserCore->BeforeResourceLoadHandler = handler; }
        }

        virtual property IBeforeMenu^ BeforeMenuHandler
        {
            IBeforeMenu^ get() { return _browserCore->BeforeMenuHandler; }
            void set(IBeforeMenu^ handler) { _browserCore->BeforeMenuHandler = handler; }
        }

        virtual property IAfterResponse^ AfterResponseHandler
        {
            IAfterResponse^ get() { return _browserCore->AfterResponseHandler; }
            void set(IAfterResponse^ handler) { _browserCore->AfterResponseHandler = handler; }
        }

        virtual void OnInitialized();

        virtual void Load(String^ url);
        virtual void LoadHtml(String^ html);
        virtual void Stop();
        virtual void Back();
        virtual void Forward();
        virtual void Reload();
        virtual void Reload(bool ignoreCache);
        virtual void ClearHistory();
        virtual void ShowDevTools();
        virtual void CloseDevTools();

        virtual void Undo();
        virtual void Redo();
        virtual void Cut();
        virtual void Copy();
        virtual void Paste();
        virtual void Delete();
        virtual void SelectAll();
        virtual void Print();

        void ExecuteScript(String^ script);
        Object^ EvaluateScript(String^ script);
        Object^ EvaluateScript(String^ script, TimeSpan timeout);

        virtual void SetNavState(bool isLoading, bool canGoBack, bool canGoForward);

        virtual void OnFrameLoadStart();
        virtual void OnFrameLoadEnd();
        virtual void OnTakeFocus(bool next);
        virtual void OnConsoleMessage(String^ message, String^ source, int line);

        virtual void OnApplyTemplate() override;
        virtual void SetCursor(CefCursorHandle cursor);
        virtual void SetBuffer(int width, int height, const void* buffer);
    };
}}