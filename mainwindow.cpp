#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QMessageBox>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget();
    QWidget *customWidget = addCutstomWidgets();
    QVBoxLayout *layout = new QVBoxLayout();
    programWidget = new ProgramWidget();

    layout->addWidget(customWidget);
    layout->addWidget(programWidget);
    setBackgroundRole(QPalette::Dark);
    setForegroundRole(QPalette::Light);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::red);
    //programWidget->setAutoFillBackground(true);
    programWidget->setPalette(Pal);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setWindowTitle(tr("TV Home"));
    //setCentralWidget(programWidget);
}

MainWindow::~MainWindow()
{

}
QWidget* MainWindow::addCutstomWidgets()
{
    QLabel *imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    QImage image((QString)"filename.jpg");
    if (image.isNull()) {
        QMessageBox::information(this, tr("Image Viewer"),
                                 tr("Cannot load %1. %2").arg("fileName", QDir::currentPath()));
        return NULL;
    }
    imageLabel->setPixmap(QPixmap::fromImage(image));
    //scaleFactor = 1.0;

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);

    return scrollArea;
}

void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();

    if (!indexes.isEmpty()) {
        //removeAct->setEnabled(true);
        //editAct->setEnabled(true);
    } else {
        //removeAct->setEnabled(false);
        //editAct->setEnabled(false);
    }
}
