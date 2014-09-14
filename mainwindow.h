#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "programwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateActions(const QItemSelection &selection);

private:
    ProgramWidget *programWidget;

    QWidget* addCutstomWidgets();
};

#endif // MAINWINDOW_H
