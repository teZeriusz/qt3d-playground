#include "TeaServiceView.h"
#include "TeaService.h"

#include "sceneobject.h"
#include <QKeyEvent>


TeaServiceView::TeaServiceView(QWindow *parent)
    : QGLView(parent)
{
    teaService = new TeaService(this);

    setOption(QGLView::ObjectPicking, true);

    connect(teaService, SIGNAL(changed()), this, SLOT(update()));
}

void TeaServiceView::initializeGL(QGLPainter *painter)
{
    teaService->service->initialize(this, painter);
}

void TeaServiceView::paintGL(QGLPainter *painter)
{
    teaService->service->draw(painter);
}

void TeaServiceView::standardLighting()
{
    teaService->changeMaterials(false);
    update();
}

void TeaServiceView::perPixelLighting()
{
    teaService->changeMaterials(true);
    update();
}

void TeaServiceView::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Tab) {
        // The Tab key turns the ShowPicking option on and off,
        // which helps show what the pick buffer looks like.
        setOption(QGLView::ShowPicking, ((options() & QGLView::ShowPicking) == 0));
        update();
    }
    QGLView::keyPressEvent(e);
}
