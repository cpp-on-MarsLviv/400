#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Models/lifemodel.h"
#include "Models/blankmodel.h"

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
    QAbstractTableModel *lifeModel = Q_NULLPTR;
    QAbstractTableModel *blankModel = Q_NULLPTR;

    shared_ptr<ModelParams> modelParams;

    bool actionIncreaseDensityLimited;
    bool actionDecreaseDensityLimited;


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
