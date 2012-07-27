#include "stdafx.h"
#pragma once

#include "RenderClientAdapter.h"
#include "WebViewEx.h"

namespace CefSharp
{
	namespace Wpf
	{

		public class RenderClientAdapterEx: public RenderClientAdapter 
		{
		private:
			gcroot<WebViewEx^> _webView;
		public:
			RenderClientAdapterEx(WebViewEx^ offscreenBrowserControl) : RenderClientAdapter((IRenderWebBrowser^)offscreenBrowserControl)
			{
				_webView = offscreenBrowserControl;
			}

			
        virtual DECL bool OnBeforePopup(CefRefPtr<CefBrowser> parentBrowser, const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo, const CefString& url, CefRefPtr<CefClient>& client, CefBrowserSettings& settings) OVERRIDE;
        virtual DECL void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
		};
	}
}
