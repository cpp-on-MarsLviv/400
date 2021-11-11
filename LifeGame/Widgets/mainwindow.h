#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Models/lifemodel.h"

#include <QMainWindow>

class QTextTableFormat;
class QTableView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QMenu *actionsMenu = Q_NULLPTR;
    QAction *startGame = Q_NULLPTR;
    QAction *stopGame = Q_NULLPTR;
    QAction *increaseDensity = Q_NULLPTR;
    QAction *decreaseDensity = Q_NULLPTR;

    QTextTableFormat *table = Q_NULLPTR;

    QTableView *tableView = Q_NULLPTR;
    LifeModel *lifeModel = Q_NULLPTR;


    void createMenu();
    void createUI();

    void wheelEvent(QWheelEvent *);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartLife();
    void onStopLife();
    void onIncreaseDensity();
    void onDecreaseDensity();
};
#endif // MAINWINDOW_H
