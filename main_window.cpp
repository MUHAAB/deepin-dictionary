#include "main_window.h"
#include <DTitlebar>
#include <QTabBar>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    mainWidget = new QTabWidget();
    toolbar = new ToolBar();
    homePage = new HomePage();
    dictPage = new DictPage();

    mainWidget->addTab(homePage, "HomePage");
    mainWidget->addTab(dictPage, "DictPage");
    mainWidget->tabBar()->hide();
    mainWidget->setCurrentIndex(0);

    this->titleBar()->setCustomWidget(toolbar, Qt::AlignVCenter, false);
    this->setCentralWidget(mainWidget);

    connect(homePage, SIGNAL(searchWord(QString)), this, SLOT(searchWord(QString)));

    connect(dictPage->returnButton, &DLinkButton::clicked, this, [=]{
        homePage->searchEdit->setText("");
        homePage->searchEdit->setFocus();
        mainWidget->setCurrentIndex(0);
    });
}

MainWindow::~MainWindow()
{

}

void MainWindow::searchWord(QString word)
{
    mainWidget->setCurrentIndex(1);
    dictPage->queryWord(word);
}
