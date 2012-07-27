
#include "RenderClientAdapterEx.h"

namespace CefSharp
{
	namespace Wpf
	{
		bool RenderClientAdapterEx::OnBeforePopup(CefRefPtr<CefBrowser> parentBrowser, const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo, const CefString& url, CefRefPtr<CefClient>& client, CefBrowserSettings& settings)
		{
			return _webView->PopupShowing(parentBrowser, popupFeatures,windowInfo, url, client, settings) ||
				RenderClientAdapter::OnBeforePopup(parentBrowser, popupFeatures,windowInfo, url, client, settings);
		}
		void RenderClientAdapterEx::OnAfterCreated(CefRefPtr<CefBrowser> browser)
		{
			RenderClientAdapter::OnAfterCreated(browser);
			_webView->PopupShown(browser);
		}
	}
}