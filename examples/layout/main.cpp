#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <qtenvironmentvariables.h>

#include "DockManager.h"
#include "DockWidget.h"
#include "ads_globals.h"

class MainWindow : public QMainWindow {
public:
    MainWindow() : QMainWindow() {
        ads::CDockManager::setConfigFlags(ads::CDockManager::DefaultOpaqueConfig);
        ads::CDockManager::setConfigFlag(ads::CDockManager::RetainTabSizeWhenCloseButtonHidden, true);
        manager = new ads::CDockManager(this);

        auto widget1 = manager->createDockWidget("First Widget");
        widget1->setWidget(new QLabel("First Label"));
        manager->addDockWidget(ads::BottomDockWidgetArea, widget1);

        auto widget2 = manager->createDockWidget("Second Widget");
        widget1->setWidget(new QLabel("Seconds Label"));
        manager->addDockWidget(ads::TopDockWidgetArea, widget2);

        auto widget3 = manager->createDockWidget("Third Widget");
        widget1->setWidget(new QLabel("Third Label"));
        manager->addDockWidget(ads::RightDockWidgetArea, widget3);

        auto widget4 = manager->createDockWidget("Fourth Widget");
        widget1->setWidget(new QLabel("Fourth Label"));
        manager->addDockWidget(ads::LeftDockWidgetArea, widget4);
    }

private:
    ads::CDockManager* manager;
};

int main(int argc, char** argv) {
    qputenv("QT_QPA_PLATFORM", "windows:darkmode=0");
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}