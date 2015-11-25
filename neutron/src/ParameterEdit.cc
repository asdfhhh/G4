/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified:	2015-07-01 14:39
* Filename:		ParameterEdit.cc
* Description: 
*************************************************/
#include "ParameterEdit.hh"
#include "QtEditer.hh"

ParameterEdit::ParameterEdit()
 : G4UImessenger()
{
	EditDirectory = new G4UIdirectory("/Edit/");
	EditDirectory->SetGuidance("UI commands specific to this example.");

	fguiCmd = new G4UIcmdWithoutParameter("/Edit/gui",this);
	fguiCmd->SetGuidance("start gui");
	fguiCmd->AvailableForStates(G4State_Idle);
}
ParameterEdit::~ParameterEdit()
{
	delete EditDirectory;
	delete fguiCmd;
}
void ParameterEdit::SetNewValue(G4UIcommand* command,G4String newValue)
{
	if( command == fguiCmd ) {
	QWidget *window=getParentWidget();
	window->show();
	}   
}
QWidget *ParameterEdit::getParentWidget() 
{

	G4Qt* interactorManager = G4Qt::getInstance ();
	bool found = false;
	QtEditer *dialog=NULL;
	if (((QApplication*)interactorManager->GetMainInteractor())) 
	{
		// look for the main window
	    QWidgetList wl = QApplication::allWidgets();
	    QWidget *widget = NULL;
	    for (int i=0; i < wl.size(); i++) 
		{
			widget = wl.at(i);
			if ((found== false) && (widget->inherits("QMainWindow"))) 
			{
				//dialog = new QDialog(widget,Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
				dialog = new QtEditer(widget);
				found = true;
			}
		}
    	if (found==false) 
		{
			#ifdef G4DEBUG_VIS_OGL
			printf("G4OpenGLQtViewer::CreateMainWindow case Qapp exist, but not found\n");
			#endif
			//dialog = new QDialog();
			dialog = new QtEditer();
		}
	} 
	else 
	{
		#ifdef G4DEBUG_VIS_OGL
    	printf("G4OpenGLQtViewer::CreateMainWindow case Qapp exist\n");
		#endif
		//dialog= new QDialog();
		dialog = new QtEditer();
		#ifdef G4DEBUG_VIS_OGL
		printf("G4OpenGLQtViewer::GetParentWidget fGLWidget\n");
		#endif
	}
	if (found) 
	{
		return dialog;
	} 
	else 
	{
		return NULL;
	}
}
