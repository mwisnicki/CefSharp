#include "stdafx.h"
#pragma once

//#include "SchemeHandler.h"

using namespace System;
using namespace System::IO;


namespace CefSharp
{
	namespace Wpf
	{

		public delegate bool SchemeHandlerDelegate(IRequest^ request, String^% mimeType, Stream^% stream);

		public ref class DelegateSchemeHandler : public ISchemeHandler
		{
		private:
			SchemeHandlerDelegate^ _handler;
		public:
			DelegateSchemeHandler(SchemeHandlerDelegate^ handler)
			{
				_handler = handler;
			}
			virtual bool ProcessRequest(IRequest^ request, String^% mimeType, Stream^% stream);
		};

		public ref class DelegateSchemeHandlerFactory : public ISchemeHandlerFactory
		{
		private:
			SchemeHandlerDelegate^ _handler;
		public:
			DelegateSchemeHandlerFactory(SchemeHandlerDelegate^ handler)
			{
				_handler = handler;
			}

			virtual ISchemeHandler^ Create();
		};
	}
}