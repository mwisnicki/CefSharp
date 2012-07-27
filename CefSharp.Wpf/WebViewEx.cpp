
#include "WebViewEx.h"
#include "RenderClientAdapterEx.h"
#include "DevToolsShowingEventArgs.h"

namespace CefSharp
{
	namespace Wpf
	{
		void WebViewEx::Initialize(String^ address, BrowserSettings^ settings)
		{
			WebView::Initialize(address, settings);
			
			WebView::RequestHandler = this;
		}
		CefRefPtr<RenderClientAdapter> WebViewEx::CreateClientAdapter()
		{
			return new RenderClientAdapterEx(this);
		}
		bool WebViewEx::OnBeforeResourceLoad(IWebBrowser^ browserControl, IRequestResponse^ requestResponse)
		{
			OnRequestResource(browserControl, requestResponse);
			return false;
		}
		void WebViewEx::OnRequestResource(IWebBrowser^ browserControl, IRequestResponse^ requestResponse)
		{
			RequestResource(browserControl, requestResponse);
		}

		void WebViewEx::OnFrameLoadEnd()
		{
			WebView::OnFrameLoadEnd();
			Dispatcher->Invoke(gcnew ActionHandler(this, &WebViewEx::OnLoadCompleted)); 
		}

		IntPtr WebViewEx::GetMainWindowHandle()
		{
			DevToolsShowingEventArgs^ args = gcnew DevToolsShowingEventArgs();

			DevToolsShowing(this, args);
			if(args->_customWindow != nullptr)
			{
				return (gcnew WindowInteropHelper(args->_customWindow))->Handle;
			}
			return IntPtr::Zero;
		}

		bool WebViewEx::PopupShowing(CefRefPtr<CefBrowser> parentBrowser,
			const CefPopupFeatures& popupFeatures, 
			CefWindowInfo& windowInfo,
			const CefString& url, 
			CefRefPtr<CefClient>& client,
			CefBrowserSettings& settings)
		{
			
			String^ urlString = toClr(url);
			if(showingDevTools && urlString->StartsWith("chrome-devtools://") )
			{
				settings.user_style_sheet_enabled = false;
				IntPtr mwHandle = (IntPtr)Dispatcher->Invoke( gcnew GetMainWindowHandleHandler(this, &WebViewEx::GetMainWindowHandle));
				if(mwHandle != IntPtr::Zero)
				{
					RECT rect;
					windowInfo.SetAsChild(static_cast<HWND>(mwHandle.ToPointer()), rect);
				}
			}			
			return false;
		}


		DevToolsControl^ WebViewEx::CreateDevToolsControl(IntPtr handle)
		{			
			return gcnew DevToolsControl( HandleRef(this, handle));			
		}

		void WebViewEx::PopupShown(CefRefPtr<CefBrowser> browser) 
		{
			if(showingDevTools)
			{
				showingDevTools = false;
				HWND handle = browser->GetWindowHandle();
				DevToolsControl^ devTools = (DevToolsControl^)Dispatcher->Invoke( gcnew CreateDevToolsControlHandler(this, &WebViewEx::CreateDevToolsControl), IntPtr(handle));
				devTools->SetBrowser(browser);
				Dispatcher->Invoke( gcnew DevToolsShowedHandler(this, &WebViewEx::OnShowDevTools), devTools);
			}
		}

		void WebViewEx::OnShowDevTools(DevToolsControl^ devTools)
		{
			DevToolsShowed(devTools);
		}

		void WebViewEx::OnLoadCompleted()
		{
			LoadCompleted(this, EventArgs::Empty);
		}

		void WebViewEx::ShowDevTools()
		{
			showingDevTools = true;
			WebView::ShowDevTools();
		}
	}
}