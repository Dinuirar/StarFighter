#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    QGraphicsRectItem *rect = scene.addRect(QRect(0, 0, 100 , 100));
    //QGraphicsItem *item = scene.itemAt(50, 50);
    scene.addText("hello world!");

    QString filename = "../graphics/basic_asteroid.png";
    QImage img_ast( filename );
//    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(img_ast));
    //QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(img_ast));

    // item->setScale(0.5);
    //scene->addItem(item);

    QGraphicsView view(&scene);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "StarCruise"));
    view.resize(400, 300);
    view.show();

    return a.exec();
}
