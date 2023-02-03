#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setContextMenuPolicy( Qt::CustomContextMenu );
    connect(ui->textEdit, &QTextEdit::customContextMenuRequested, this, &MainWindow::ShowContextMenu);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ShowContextMenu(const QPoint &pos)
{
    QMenu contextMenu;

    QAction *act1 = contextMenu.addAction("Act 1");

    QAction clearAction("Clear", this);

    connect(&clearAction, &QAction::triggered, ui->textEdit, &QTextEdit::clear);

    contextMenu.addAction(&clearAction);

    QAction *res = contextMenu.exec(ui->textEdit->viewport()->mapToGlobal(pos));
}
