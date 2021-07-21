module;
#include<windows.h>
#include<string>
export module kbdmx.Assets;
import BKCL.EConsole;
using std::wstring;
namespace kbdmx::Assets
{
	export{
		wstring Version = L"1.5.0.1 Beta 1";
		wstring Title = L"ø‡±∆¥Û√∞œ’ v" + Version;
		int WindowWidth = 100;
		int WindowHeight = 25;
		wstring ChineseFontFaceName = L"Microsoft YaHei Mono";
		wstring EnglishFontFaceName = L"Cascadia Mono";
		int ChineseFontHeight = 20;
		int EnglishFontHeight = 20;
	}

	bool exist = false;
	int CALLBACK EnumFontsProc(const LOGFONTW* pfont, const TEXTMETRIC* pTextMetric, DWORD dw, LPARAM lParam)
	{
		exist = true;
		return 1;
	}

	export bool IsFontExist(const wstring& face_name)
	{
		static LOGFONTW tmp;
		ZeroMemory((char*)&tmp, sizeof tmp);
		tmp.lfCharSet = DEFAULT_CHARSET;
		wcscpy_s(tmp.lfFaceName, face_name.data());
		exist = false;
		EnumFontFamiliesExW((HDC)BKCL::EConsole::GetHDC(), &tmp, EnumFontsProc, 0, 0);
		return exist;
	}

}