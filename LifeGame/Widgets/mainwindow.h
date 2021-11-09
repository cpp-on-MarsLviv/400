#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QMenu *actionsMenu = Q_NULLPTR;
    QAction *startGame = Q_NULLPTR;
    QAction *stopGame = Q_NULLPTR;
    QAction *increaseDensity = Q_NULLPTR;
    QAction *decreaseDensity = Q_NULLPTR;

    void createMenu();

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
