#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <QtGui/QMainWindow>
#include "ui_stylesheet.h"

class StyleSheet : public QMainWindow
{
    Q_OBJECT

public:
    StyleSheet(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~StyleSheet();
protected:
    virtual void keyPressEvent ( QKeyEvent * event );
private:
    Ui::StyleSheetClass ui;
};

#endif // STYLESHEET_H
