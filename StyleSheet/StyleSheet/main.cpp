#include "stylesheet.h"
#include <QtGui/QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ¼ÓÔØÑùÊ½
    QString skinPath = qApp->applicationDirPath() + "/skin/";
    QString winMainCss = skinPath + "skin.css";
    QFile file(winMainCss);
    if (!file.open(QIODevice::ReadOnly)) {
        Q_ASSERT(false);
    }
    QString styleSheet = file.readAll();
    QString absoluteCssPath = QDir(skinPath).absolutePath();
    styleSheet.replace("%skinpath%",absoluteCssPath,Qt::CaseInsensitive);
    a.setStyleSheet(styleSheet);
    file.close();

    StyleSheet w;
    w.show();
    return a.exec();
}
