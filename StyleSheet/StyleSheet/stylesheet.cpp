#include "stylesheet.h"
#include <QDir>
#include <QKeyEvent>

StyleSheet::StyleSheet(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

    QWebSettings * settings = ui.webView->settings();
    QWebSettings::globalSettings();   
    settings->setAttribute(QWebSettings::PluginsEnabled, true);  
    settings->setAttribute(QWebSettings::JavaEnabled, true);  
    settings->setAttribute(QWebSettings::JavascriptEnabled, true);
    settings->setAttribute(QWebSettings::JavascriptCanOpenWindows, true); 
    settings->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);   
    settings->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);  
    settings->setAttribute(QWebSettings::SpatialNavigationEnabled, true);  
    settings->setAttribute(QWebSettings::LinksIncludedInFocusChain, true); 
    settings->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true); 
    settings->setAttribute(QWebSettings::AutoLoadImages, true);
    ui.webView->load(QUrl("http://blog.csdn.net/yuanzhangmei1/article/details/7724077"));
}

StyleSheet::~StyleSheet()
{

}

void StyleSheet::keyPressEvent( QKeyEvent * event )
{
    if (event->key() == Qt::Key_F8) {
        QString skinPath = qApp->applicationDirPath() + "/skin/";
        QString winMainCss = skinPath + "skin.css";
        QFile file(winMainCss);
        if (!file.open(QIODevice::ReadOnly))
            Q_ASSERT(false);
        QString styleSheet = file.readAll();
        QString absoluteCssPath = QDir(skinPath).absolutePath();
        styleSheet.replace("%skinpath%",absoluteCssPath,Qt::CaseInsensitive);
        this->setStyleSheet(styleSheet);
        file.close();
    }
    QMainWindow::keyPressEvent(event);
}
