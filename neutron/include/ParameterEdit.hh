/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:47
* Filename: ParameterEdit.hh
* Description: 
*************************************************/
#ifndef ParameterEdit_h
#define ParameterEdit_h 1

#include "globals.hh"
#include "G4UImessenger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIdirectory.hh"
#include "G4Qt.hh"
#include "G4UIQt.hh"
#include <qwidget.h>
#include <qapplication.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qdialog.h>
#include <qpushbutton.h>
#include <qprocess.h>
#include <qdesktopwidget.h>
#include <qmenu.h>
#include <qimagewriter.h>
#include <qtextedit.h>
#include <qtreewidget.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qprinter.h>
#include <qdatetime.h>
#include <qpainter.h>
#include <qgl.h> // include <qglwidget.h>
#include <qdialog.h>
#include <qcolordialog.h>
#include <qevent.h> //include <qcontextmenuevent.h>
#include <qobject.h>
#include <qgroupbox.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qsignalmapper.h>
#include <qmainwindow.h>
#include <qtablewidget.h>
#include <qheaderview.h>
#include <qscrollarea.h>
#include <qsplitter.h>
#include <qcheckbox.h>
#include <qcursor.h>
#include <qobject.h>
#include <qpoint.h>
#include <qpixmap.h>


class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithoutParameter;

class G4OpenGLSceneHandler;
class G4UImanager;
class G4Text;
class G4UIcommand;
class QGLWidget;
class QDialog;
class QTextEdit;
class QContextMenuEvent;
class QMenu;
class QImage;
class QAction;
class QTabWidget;
class QMouseEvent;
class QKeyEvent;
class QWheelEvent;
class QProcess;
class QTime;
class QVBoxLayout;
class QPushButton;
class QSlider;
class QTreeWidgetItem;
class QTreeWidget;
class QColor;
class G4OpenGLSceneHandler;
class G4OpenGLQtMovieDialog;
class QLineEdit;
class QSignalMapper;
class G4UIQt;
class QTableWidget;
class QTableWidgetItem;
class QScrollArea;
class QSplitter;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
class ParameterEdit: public G4UImessenger
{
	public:
		ParameterEdit( );
		virtual ~ParameterEdit();
		virtual void SetNewValue(G4UIcommand*, G4String);
	private:
		G4UIdirectory*           EditDirectory;
		G4UIcmdWithoutParameter* fguiCmd; 
		QWidget* getParentWidget();
};
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
