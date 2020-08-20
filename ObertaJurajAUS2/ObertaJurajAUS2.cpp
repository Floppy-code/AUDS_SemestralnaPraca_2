#include "stdafx.h"
#include "Manazer.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace ObertaJurajAUS2;

void guiRun(Manazer* m)
{
	MainForm^ mainForm = gcnew MainForm();	//Vytvorenie okna
	mainForm->SetManazer(m);				//Pridane manazera

	Application::Run(mainForm);
}

int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Manazer* m = new Manazer();

	m->NacitajDataKraj();	//Nacitanie udajov
	m->NacitajDataOkres();
	m->NacitajDataObec();

	guiRun(m);		//Spustenie GUI

	delete m;
	_CrtDumpMemoryLeaks();
    return 0;
}
