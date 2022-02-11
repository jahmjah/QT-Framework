#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionCopiar_triggered();

    void on_actionGuardar_triggered();

    void on_actionPegar_triggered();

    void on_actionCortar_triggered();

    void on_actionCreditos_NotePad_triggered();

    void on_actionDeshacer_triggered();

    void on_actionNuevo_triggered();

    void on_actionCreditos_SDK_triggered();

    void on_actionImprimir_triggered();

    void on_actionAbrir_triggered();

    void on_actionGuardar_como_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
