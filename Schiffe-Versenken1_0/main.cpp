#include "schiffe.h"
#include "uboote.h"
#include "brett.h"


class Fenster : public QMainWindow {
public:
    Fenster(QWidget *parent = nullptr) : QMainWindow(parent), schiff(nullptr) // Initialisiere schiff als nullptr
    {
        this->setWindowTitle("Schiffe versenken");
        this->resize(1950, 1080);

        // Füge das Brett hinzu
        brett = new Brett();

        // Füge die QGraphicsScene des Schiffs zum Fenster hinzu
        QGraphicsView* view = new QGraphicsView(brett->getScene(), this);


        setCentralWidget(view);

        createMenus();
    }

private slots:
    void changeWindowSize(){
        if(isFullScreen()){
            showNormal();
        } else {
            showFullScreen();
        }
    }

private:
    Schiffe* schiff;
    Brett* brett;
    void createMenus(){
        QMenuBar *bar = menuBar();
        QMenu *Optionen = bar->addMenu(tr("&Optionen"));
        Optionen->addAction(new QAction("Einstellungen",this));

        QAction *Fenstermodus = new QAction(tr("Fenstermodus"), this);
        Fenstermodus->setShortcut(QKeySequence(Qt::Key_F11));
        Optionen->addAction(Fenstermodus);

        connect(Fenstermodus, &QAction::triggered, this, &Fenster::changeWindowSize);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fenster f;
    f.showFullScreen();
    return a.exec();
}
