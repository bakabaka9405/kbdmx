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
		eout << folive<<bwhite << "��ӭ������ƴ�ð�գ�" << endl;
		eout << fwhite<<bblack << "�汾��" << Assets::Version << "\t���ߣ�bakabaka\t�ر���л�������̡�MOCERIS STUDIO" << endl;
		eout << "build on " << __DATE__ << " " << __TIME__ << endl;
		Pause();
	}
}