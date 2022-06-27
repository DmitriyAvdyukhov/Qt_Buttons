#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>
#include <QPalette>
#include "buttons.h"


void ButtonClicked()
{

}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QWidget wgt;

  //установка обычной кнопки
  QPushButton* pcmd_normal = new QPushButton("&Normal button");

  // установка кнопки-выключателя
  QPushButton* pcmd_toggle = new QPushButton("&Toggle button");
  pcmd_toggle->setCheckable(true);
  pcmd_toggle->setChecked(true);

  //установка скрытой кнопки
  QPushButton* pcmd_flat = new QPushButton("&Button flat");
  pcmd_flat->setFlat(true);

  //установка кнопки с изображением
  QPixmap pix("Y:/source_qt/First/a.png");
  QPushButton* pcmd_pix = new QPushButton("&Pixmap button");
  pcmd_pix->setIcon(pix);
  pcmd_pix->setIconSize(pix.size());

  //установка кнопки выподающего меню
  QPushButton* pcmd_menu = new QPushButton("&Menu");
  QMenu* menu = new QMenu(pcmd_menu);
  menu->addAction("Item1");
  menu->addAction("Item2");
  menu->addAction("&Quit", &a, SLOT(quit()));
  pcmd_menu->setMenu(menu);

  //установка обычного флажка
  QCheckBox* pchk_normal = new QCheckBox("&Normal check box");
  pchk_normal->setChecked(true);

  //установка флажка с неопределенным состоянием вкл, выкл, неопределен
  QCheckBox* pchk_tristate = new QCheckBox("&Tristate check box");
  pchk_tristate->setChecked(true);
  pchk_tristate->setCheckState(Qt::PartiallyChecked);


  //установка переключателей
  QRadioButton* prad_red = new QRadioButton("&Red");

  QRadioButton* prad_green = new QRadioButton("&Green");
  prad_green->setChecked(true);

  QRadioButton* prad_blue = new QRadioButton("&Blue");

  QHBoxLayout* phbox_layout = new QHBoxLayout;
  phbox_layout->addWidget(prad_red);
  phbox_layout->addWidget(prad_green);
  phbox_layout->addWidget(prad_blue);


  // Layout setup
  QVBoxLayout* pvbox_layout = new QVBoxLayout;
  pvbox_layout->addWidget(pcmd_normal);
  pvbox_layout->addWidget(pcmd_toggle);
  pvbox_layout->addWidget(pcmd_flat);
  pvbox_layout->addWidget(pcmd_pix);
  pvbox_layout->addWidget(pcmd_menu);
  pvbox_layout->addWidget(pchk_normal);
  pvbox_layout->addWidget(pchk_tristate);
  pvbox_layout->addLayout(phbox_layout);

  wgt.setLayout(pvbox_layout);
  wgt.setGeometry(300, 200, 200, 400);
  wgt.setWindowTitle("Buttons and flags");
  wgt.show();

  Buttons buttons;
  buttons.show();
  return a.exec();
}
