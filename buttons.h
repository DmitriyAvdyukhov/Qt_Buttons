#pragma once

#include <QGroupBox>
#include <QtWidgets>

class QCheckBox;
class QRadioButton;

class Buttons : public QGroupBox
{
     Q_OBJECT
private:
  QCheckBox* m_pchk_;
  QRadioButton* m_prad_red_;
  QRadioButton* m_prad_green_;
  QRadioButton* m_prad_blue_;

public:
    Buttons(QWidget* pwgt = 0);

public slots:
    void SlotButtonClicked();
};

