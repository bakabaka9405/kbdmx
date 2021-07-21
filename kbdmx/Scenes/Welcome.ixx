module;
#include<string>
export module kbdmx.Scenes.Welcome;
import BKCL.EConsole.Eiostream;
import kbdmx.Assets;
using namespace std;
using namespace BKCL::EConsole;
namespace kbdmx::Scenes::Welcome
{
	export void Display()
	{
		Clear();
		eout << folive<<bwhite << "欢迎来到苦逼大冒险！" << endl;
		eout << fwhite<<bblack << "版本：" << Assets::Version << "\t作者：bakabaka\t特别鸣谢：彭于晏、MOCERIS STUDIO" << endl;
		eout << "build on " << __DATE__ << " " << __TIME__ << endl;
		Pause();
	}
}