module;
#include<windows.h>
#include<tchar.h>
#include<fstream>
#include<string>
#include<direct.h>
#include"simdjson/simdjson.h"
export module kbdmx.IO;
import kbdmx.Assets;
import BKCL.EConsole.Eiostream;
using namespace BKCL::EConsole;
using namespace std;
namespace kbdmx::IO
{
	void LoadSetting()
	{
		/*simdjson::dom::parser parser;
		simdjson::dom::element tweets = parser.load("data//setting.json");
		if (tweets["ChineseFontFaceName"].is_string())
		{
			eout << string(tweets["ChineseFontFaceName"]) << endl;
			Pause();
		}
		else
		{
			eout << "Key Not Found." << endl;
			Pause();
		}*/
	}

	export void Init()
	{
		CreateDirectory(_T(".//data"), NULL);
		ifstream fin;
		fin.open(_T("data//setting.json"));
		if (fin.is_open())
		{
			fin.close();
			LoadSetting();
		}
	}
}