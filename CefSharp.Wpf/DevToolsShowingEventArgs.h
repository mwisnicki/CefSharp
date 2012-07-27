#pragma once
using namespace System::Windows;

namespace CefSharp{
	namespace Wpf{
		public ref class DevToolsShowingEventArgs : public System::EventArgs
		{
		internal:
			Window^ _customWindow;

		public:
			DevToolsShowingEventArgs()
			{

			}
			void SetParentWindow(Window^ customWindow)
			{
				_customWindow = customWindow;
			}
		};
	}}
