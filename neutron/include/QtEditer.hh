/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:48
* Filename: QtEditer.hh
* Description: 
*************************************************/
#ifndef QtEditer_H
#define QtEditer_H
#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <qdialog.h>

class QtEditer : public QDialog
{
  public:
    QtEditer(QWidget *parent = 0);  
	QLineEdit *nameLine;
    QTextEdit *addressText;

};

#endif
