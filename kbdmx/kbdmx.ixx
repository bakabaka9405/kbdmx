module;
#include<easyx.h>
#include<string>
#include<windows.h>
export module kbdmx;
import BKCL.EConsole.Eiostream;
import kbdmx.Assets;
import kbdmx.IO;
import kbdmx.Scenes;
using namespace std;
namespace kbdmx
{
	void Init()
	{
		kbdmx::IO::Init();
		LOGFONT cfont, efont;
		ZeroMemory((char*)&cfont, sizeof cfont);
		cfont.lfHeight = Assets::ChineseFontHeight;
		wcscpy_s(cfont.lfFaceName, Assets::ChineseFontFaceName.data());
		efont = cfont;
		efont.lfHeight = Assets::EnglishFontHeight;
		wcscpy_s(efont.lfFaceName, Assets::EnglishFontFaceName.data());
		BKCL::EConsole::Init(80, 25, efont, cfont);
		wstring lacked_font;
		if (!Assets::IsFontExist(Assets::ChineseFontFaceName))
			lacked_font += Assets::ChineseFontFaceName + L"\r\n";
		if (!Assets::IsFontExist(Assets::EnglishFontFaceName))
			lacked_font += Assets::EnglishFontFaceName + L"\r\n";
		if (!lacked_font.empty())
		{
			wstring information = L"缺少以下字体\r\n" + lacked_font + L"字体的缺失可能会影响游戏体验，是否继续？";
			int result = MessageBoxW(NULL, information.data(), L"信息", MB_YESNO | MB_ICONINFORMATION);
			if (result != IDYES)return;
		}
	}
	export void Run()
	{
		Init();
		Scenes::Welcome::Display();
	}
}