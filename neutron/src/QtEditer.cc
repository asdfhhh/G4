/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2015-07-01 14:38
* Filename: QtEditer.cc
* Description: this is a script for a QT based widget 
*************************************************/
#include "QtEditer.hh"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>
QtEditer::QtEditer(QWidget *parent)
    : QDialog(parent)
{


	QLabel *nameLabel = new QLabel(tr("Name:"));
    nameLine = new QLineEdit;

    QLabel *addressLabel = new QLabel(tr("Address:"));
    addressText = new QTextEdit;
//! [constructor and input fields]

//! [layout]
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(nameLine, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(addressText, 1, 1);
//! [layout]

//![setting the layout]
    setLayout(mainLayout);
    setWindowTitle(tr("Simple Address Book"));
	setAttribute (Qt::WA_DeleteOnClose);
}

