#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include "TeaServiceView.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow mainw;
    mainw.setMinimumSize(850, 480);
    mainw.setWindowTitle(QLatin1String("Tea Service"));

    TeaServiceView view;
    mainw.setCentralWidget(&view);
    view.setFocus();

    view.camera()->setEye(QVector3D(0, 3, 10));

    QMenu *menu = mainw.menuBar()->addMenu(QLatin1String("Effects"));

    QAction *standardLighting = new QAction(QLatin1String("Standard lighting"), &mainw);
    menu->addAction(standardLighting);
    QObject::connect(standardLighting, SIGNAL(triggered()), &view, SLOT(standardLighting()));

    QAction *perPixelLighting = new QAction(QLatin1String("Per-pixel lighting"), &mainw);
    menu->addAction(perPixelLighting);
    QObject::connect(perPixelLighting, SIGNAL(triggered()), &view, SLOT(perPixelLighting()));

    menu->addSeparator();

    QAction *exitAction = new QAction(QLatin1String("E&xit"), &mainw);
    menu->addAction(exitAction);
    QObject::connect(exitAction, SIGNAL(triggered()), &app, SLOT(quit()));

#ifdef Q_OS_SYMBIAN
    mainw.setAttribute(Qt::WA_LockLandscapeOrientation, true);
    mainw.showFullScreen();
#endif

    view.updateGL();
    mainw.update();
    mainw.show();
    return app.exec();
}
