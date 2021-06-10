#include "Photino.h"

#ifdef _WIN32
#define EXPORTED __declspec(dllexport)
#else
#define EXPORTED
#endif

extern "C"
{
#ifdef _WIN32
	EXPORTED void Photino_register_win32(HINSTANCE hInstance)
	{
		Photino::Register(hInstance);
	}

	EXPORTED HWND Photino_getHwnd_win32(Photino* instance)
	{
		return instance->getHwnd();
	}
#elif __APPLE__
	EXPORTED void Photino_register_mac()
	{
		Photino::Register();
	}
#endif

	EXPORTED Photino* Photino_ctor(PhotinoInitParams* initParams)
	{
		return new Photino(initParams);
	}

	EXPORTED void Photino_dtor(Photino* instance)
	{
		delete instance;
	}

	EXPORTED void Photino_Center(Photino* instance)
	{
		instance->Center();
	}

	EXPORTED void Photino_Close(Photino* instance)
	{
		instance->Close();
	}

	EXPORTED void Photino_GetMaximized(Photino* instance, bool* isMaximized)
	{
		instance->GetMaximized(isMaximized);
	}

	EXPORTED void Photino_GetMinimized(Photino* instance, bool* isMinimized)
	{
		instance->GetMinimized(isMinimized);
	}

	EXPORTED void Photino_GetPosition(Photino* instance, int* x, int* y)
	{
		instance->GetPosition(x, y);
	}

	EXPORTED unsigned int Photino_GetScreenDpi(Photino* instance)
	{
		return instance->GetScreenDpi();
	}

	EXPORTED void Photino_GetSize(Photino* instance, int* width, int* height)
	{
		instance->GetSize(width, height);
	}

	EXPORTED void Photino_Maximize(Photino* instance)
	{
		instance->Maximize();
	}

	EXPORTED void Photino_Minimize(Photino* instance)
	{
		instance->Minimize();
	}

	EXPORTED void Photino_NavigateToString(Photino* instance, AutoString content)
	{
		instance->NavigateToString(content);
	}

	EXPORTED void Photino_NavigateToUrl(Photino* instance, AutoString url)
	{
		instance->NavigateToUrl(url);
	}

	EXPORTED void Photino_Restore(Photino* instance)
	{
		instance->Restore();
	}

	EXPORTED void Photino_SendWebMessage(Photino* instance, AutoString message)
	{
		instance->SendWebMessage(message);
	}

	EXPORTED void Photino_SetIconFile(Photino* instance, AutoString filename)
	{
		instance->SetIconFile(filename);
	}

	EXPORTED void Photino_SetPosition(Photino* instance, int x, int y)
	{
		instance->SetPosition(x, y);
	}

	EXPORTED void Photino_SetResizable(Photino* instance, int resizable)
	{
		instance->SetResizable(resizable);
	}

	EXPORTED void Photino_SetSize(Photino* instance, int width, int height)
	{
		instance->SetSize(width, height);
	}

	EXPORTED void Photino_SetTitle(Photino* instance, AutoString title)
	{
		instance->SetTitle(title);
	}

	EXPORTED void Photino_SetTopmost(Photino* instance, int topmost)
	{
		instance->SetTopmost(topmost);
	}

	EXPORTED void Photino_ShowMessage(Photino* instance, AutoString title, AutoString body, unsigned int type)
	{
		instance->ShowMessage(title, body, type);
	}

	EXPORTED void Photino_WaitForExit(Photino* instance)
	{
		instance->WaitForExit();
	}



	//Callbacks
	EXPORTED void Photino_AddCustomScheme(Photino* instance, AutoString scheme, WebResourceRequestedCallback requestHandler)
	{
		instance->AddCustomScheme(scheme, requestHandler);
	}

	EXPORTED void Photino_GetAllMonitors(Photino* instance, GetAllMonitorsCallback callback)
	{
		instance->GetAllMonitors(callback);
	}

	EXPORTED void Photino_SetClosingCallback(Photino* instance, ClosingCallback callback)
	{
		instance->SetClosingCallback(callback);
	}

	EXPORTED void Photino_SetMovedCallback(Photino* instance, MovedCallback callback)
	{
		instance->SetMovedCallback(callback);
	}

	EXPORTED void Photino_SetResizedCallback(Photino* instance, ResizedCallback callback)
	{
		instance->SetResizedCallback(callback);
	}



	EXPORTED void Photino_Invoke(Photino* instance, ACTION callback)
	{
		instance->Invoke(callback);
	}
}
