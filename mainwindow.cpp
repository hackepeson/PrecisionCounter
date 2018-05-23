#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  m_pElapsedTimer = new QElapsedTimer();
  m_pElapsedTimer->start();

  bool test = m_pElapsedTimer->isMonotonic();



  m_pTimer = new QTimer();
  m_pTimer->start(150);


  connect(m_pTimer, SIGNAL(timeout()),SLOT(updateTimer()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::updateTimer()
{
  //ui->lcdNumberPrecisionCounter->display( (int)m_pElapsedTimer->nsecsElapsed());
  ui->lcdNumberPrecisionCounter->display( (int)m_pElapsedTimer->elapsed());
  m_pElapsedTimer->restart();

}
