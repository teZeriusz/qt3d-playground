#include <QGuiApplication>
#include <QTimer>
#include "TeaServiceView.h"


int main(int argc, char *argv[]) {
    /*
    QGuiApplication app(argc, argv);
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
*/

    QGuiApplication app(argc, argv);

    TeaServiceView view;
    QStringList args = QGuiApplication::arguments();
    int w_pos = args.indexOf("-width");
    int h_pos = args.indexOf("-height");
    if (w_pos >= 0 && h_pos >= 0)
    {
        bool ok = true;
        int w = args.at(w_pos + 1).toInt(&ok);
        if (!ok)
        {
            qWarning() << "Could not parse width argument:" << args;
            return 1;
        }
        int h = args.at(h_pos + 1).toInt(&ok);
        if (!ok)
        {
            qWarning() << "Could not parse height argument:" << args;
            return 1;
        }
        view.resize(w, h);
    }
    else
    {
        view.resize(800, 600);
    }
    view.show();

    // TODO: QWindow has no setFocus function
    // view.setFocus();

    view.camera()->setEye(QVector3D(0, 3, 10));

    if (args.contains("-per-pixel-lighting"))
    {
        QTimer::singleShot(0, &view, SLOT(perPixelLighting()));
    }

    view.show();

    return app.exec();
}
