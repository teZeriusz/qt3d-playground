#ifndef TEASERVICEVIEW_H
#define TEASERVICEVIEW_H

#include <qglview.h>


class TeaService;


class TeaServiceView : public QGLView {
    Q_OBJECT

public:
    TeaServiceView(QWidget *parent=0);

public slots:
    void standardLighting();
    void perPixelLighting();

protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);
    void keyPressEvent(QKeyEvent *e);

private:
    TeaService *teaService;
};

#endif // TEASERVICEVIEW_H
