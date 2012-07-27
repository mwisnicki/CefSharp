#pragma once

#include "WebView.h"
#include "DevToolsShowingEventArgs.h"

using namespace System;
using namespace System::Net;
namespace CefSharp
{
	namespace Wpf
	{
		
		public delegate void RequestResourceHandler(IWebBrowser^ browserControl, IRequestResponse^ requestResponse);
		
		public ref class DevToolsControl : public HwndHost
		{
		private:
			HandleRef _childHandle;
			MCefRefPtr<CefBrowser> _browser; 
			
		protected:	
			virtual	HandleRef BuildWindowCore(HandleRef hwndParent) override
			{
				return _childHandle;
			}
			virtual	void DestroyWindowCore(HandleRef hwndParent) override
			{
			}
		public:
			DevToolsControl(HandleRef ref) : HwndHost()
			{
				_childHandle = ref;
			}	
			
			void SetBrowser(CefRefPtr<CefBrowser> browser)
			{
				_browser =  browser.get();
			}
			void ShowDevTools()
			{
				_browser->ShowDevTools() ;
			}
			void Reload()
			{
				_browser->Reload() ;
			}
		};
		
		public delegate void DevToolsShowingHandler(Object^ sender, DevToolsShowingEventArgs^ args);
		public delegate void DevToolsShowedHandler(DevToolsControl^ devToolsControl);

		public ref class WebViewEx : public WebView, IRequestHandler
		{
		private:
			bool showingDevTools;
			delegate void ActionHandler();
			delegate IntPtr GetMainWindowHandleHandler();
			delegate DevToolsControl^ CreateDevToolsControlHandler(IntPtr handle);
			
			IntPtr GetMainWindowHandle();
			DevToolsControl^ CreateDevToolsControl(IntPtr handle);
		
			
		protected:
			virtual void Initialize(String^ address, BrowserSettings^ settings) override;
			virtual CefRefPtr<RenderClientAdapter> CreateClientAdapter() override;
		public:
			virtual event RequestResourceHandler^ RequestResource;
			virtual event DevToolsShowedHandler^ DevToolsShowed;
			virtual event DevToolsShowingHandler^ DevToolsShowing;
			virtual event EventHandler^ LoadCompleted;
			
			WebViewEx():WebView()
			{
			}

			WebViewEx(String^ address, BrowserSettings^ settings) : WebView(address,settings)
			{
			}

			virtual bool PopupShowing(CefRefPtr<CefBrowser> parentBrowser, const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo, const CefString& url, CefRefPtr<CefClient>& client, CefBrowserSettings& settings);
			virtual void PopupShown(CefRefPtr<CefBrowser> browser) ;
		
			
			
			virtual  bool OnBeforeBrowse(IWebBrowser^ browser, IRequest^ request, NavigationType naigationvType, bool isRedirect){return false;};
       virtual bool OnBeforeResourceLoad(IWebBrowser^ browser, IRequestResponse^ requestResponse);
	   virtual void OnResourceResponse(IWebBrowser^ browser, String^ url, int status, String^ statusText, String^ mimeType, WebHeaderCollection^ headers){};


			virtual void OnRequestResource(IWebBrowser^ browserControl, IRequestResponse^ requestResponse);
			virtual void OnLoadCompleted();
			virtual void OnShowDevTools(DevToolsControl^ devTools);
			virtual void OnFrameLoadEnd() override;
			virtual void ShowDevTools() override;

		};

	}
}
