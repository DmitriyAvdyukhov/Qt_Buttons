#include "buttons.h"

Buttons::Buttons(QWidget * pwgt) : QGroupBox("QGroupBoxp", pwgt)
{
  resize(250, 150);
  setCheckable(true);
  setChecked(true);
  setWindowTitle("Colors buttons");
  m_pchk_ = new QCheckBox("&Light");
  m_pchk_->setChecked(true);

  m_prad_red_ = new QRadioButton("&Red");
  m_prad_green_ = new QRadioButton("&Green");
  m_prad_green_->setChecked(true);
  m_prad_blue_ = new QRadioButton("&Blue");

  connect(m_pchk_, SIGNAL(clicked()), SLOT(SlotButtonClicked()));
  connect(m_prad_red_, SIGNAL(clicked()), SLOT(SlotButtonClicked()));
  connect(m_prad_green_, SIGNAL(clicked()), SLOT(SlotButtonClicked()));
  connect(m_prad_blue_, SIGNAL(clicked()), SLOT(SlotButtonClicked()));

  QPushButton* pcmd = new QPushButton("&Exit");
  connect(pcmd, SIGNAL(clicked()), qApp, SLOT(quit()));

  QVBoxLayout* pvbox_layot = new QVBoxLayout;
  pvbox_layot->addWidget(m_pchk_);
  pvbox_layot->addWidget(m_prad_red_);
  pvbox_layot->addWidget(m_prad_green_);
  pvbox_layot->addWidget(m_prad_blue_);
  pvbox_layot->addWidget(pcmd);
  setLayout(pvbox_layot);

  SlotButtonClicked();
}


void Buttons::SlotButtonClicked()
{
  QPalette pal = palette();
  int n_light = m_pchk_->isChecked() ? 150 : 100;
  if(m_prad_red_->isChecked())
    {
      pal.setColor(backgroundRole(), QColor(Qt::red).lighter(n_light));
    }
  else if(m_prad_green_->isChecked())
    {
      pal.setColor(backgroundRole(), QColor(Qt::green).lighter(n_light));
    }
  else if(m_prad_blue_->isChecked())
    {
      pal.setColor(backgroundRole(), QColor(Qt::blue).lighter(n_light));
    }
  setPalette(pal);
}
