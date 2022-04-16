#include <QDebug>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>

#include "clientcreditswindow.h"

ClientCreditsWindow::ClientCreditsWindow()
{
    setWindowTitle("Управление кредитами");
    setFixedWidth(300);
    setFixedHeight(300);

    QLabel *creditsListLabel = new QLabel("Список кредитов:", this);

    creditsListWidget = new QListWidget(this);
    creditsListWidget->addItem("2942049");

    connect(creditsListWidget, &QListWidget::itemClicked, this, &ClientCreditsWindow::changeCurrentCreditId);

    QPushButton *showInfo = new QPushButton("Информация о кредите", this);
    QPushButton *takeLoan = new QPushButton("Взять кредит", this);
    QPushButton *makeMonthlyPayment = new QPushButton("Совершить платёж по кредиту", this);

    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(creditsListLabel, 0, 0);
    gridLayout->addWidget(creditsListWidget, 1, 0);
    gridLayout->addWidget(showInfo, 2, 0);
    gridLayout->addWidget(takeLoan, 3, 0);
    gridLayout->addWidget(makeMonthlyPayment, 4, 0);
}

void ClientCreditsWindow::changeCurrentCreditId(QListWidgetItem *item)
{
    qDebug() << "before:\n";
    qDebug() << "currentCreditId = " << currentCreditId << "\n";
    currentCreditId = item->text().toInt();
    qDebug() << "after:\n";
    qDebug() << "currentCreditId = " << currentCreditId << "\n";
}

int64_t ClientCreditsWindow::getCurrentCreditId() const
{
    if (currentCreditId < 0)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Вы должны выбрать кредит в списке");
        msgBox.exec();
        return -1;
    }
    return currentCreditId;
}
