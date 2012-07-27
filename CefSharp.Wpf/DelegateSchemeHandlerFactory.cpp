
#pragma once

#include "DelegateSchemeHandlerFactory.h"

using namespace System;
using namespace System::IO;


namespace CefSharp
{
	namespace Wpf
	{
		bool DelegateSchemeHandler::ProcessRequest(IRequest^ request, String^% mimeType, Stream^% stream)
		{
			return _handler(request, mimeType, stream);			
		}

		ISchemeHandler^ DelegateSchemeHandlerFactory::Create()
		{
			return gcnew DelegateSchemeHandler(_handler);
		}
	}
}