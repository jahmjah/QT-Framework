#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox.h"
#include <QFileDialog>
#include "qfile"
#include "QTextStream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setCentralWidget(ui->QPlainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSalir_triggered()
{
close();
}

void MainWindow::on_actionCopiar_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionGuardar_triggered()
{
    //ui->plainTextEdit->
    QFile  arch;
    QTextStream io;
    QString  nomArch;
    nomArch = QFileDialog::getSaveFileName(this,"Guardar");
    // -- comment this for test: // arch.setFileName(nomArch);
    arch.setFileName(nomArch);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!arch.isOpen()){
        QMessageBox::critical(this,"Error",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    io<<ui->plainTextEdit->toPlainText();
    arch.flush();
    arch.close();
}

void MainWindow::on_actionPegar_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionCortar_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionCreditos_NotePad_triggered()
{
  QMessageBox::about(this,"NotePad","By cmteJah");
}

void MainWindow::on_actionDeshacer_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionNuevo_triggered()
{
   // ui->plainTextEdit->document();
}

void MainWindow::on_actionCreditos_SDK_triggered()
{
    QMessageBox::aboutQt(this,"QT");
}

void MainWindow::on_actionImprimir_triggered()
{
    //ui->plainTextEdit->print(this);
}

void MainWindow::on_actionAbrir_triggered()
{
    QFile  arch;
    QTextStream io;
    QString  nomArch;
    nomArch = QFileDialog::getOpenFileName(this,"Abrir");
    arch.setFileName(nomArch);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!arch.isOpen()){
        QMessageBox::critical(this,"Error",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    ui->plainTextEdit->setPlainText(io.readAll());
    arch.close();

}

void MainWindow::on_actionGuardar_como_triggered()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    QStringList files;
    if (dialog.exec())
        files = dialog.selectedFiles();
    else
        return;

    return;
}
