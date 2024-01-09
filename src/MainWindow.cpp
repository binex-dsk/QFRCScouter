#include "MainWindow.h"

#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , Ui::MainWindow()
{
    setupUi(this);
    m_pages = {
        welcome,
        teamInfo,
        autoScouting,
        teleScouting,
        qrcode
    };

    int currentIdx;

    connect(nextButton, &QPushButton::released, this, [this, &currentIdx]() {
        int nextIdx = currentIdx + 1;
        if (nextIdx >= stackedWidget->count()) nextIdx = stackedWidget->count() - 1;
        currentIdx = nextIdx;

        stackedWidget->setCurrentWidget(m_pages.at(nextIdx));
        QElapsedTimer timer;
        timer.start();
        if (nextIdx == stackedWidget->count() - 1) {
            qrcode->setQRData(serializeData());
        }
        qDebug() << timer.elapsed();
        timer.invalidate();
    });

    connect(backButton, &QPushButton::released, this, [this, &currentIdx]() {
        int nextIdx = currentIdx - 1;
        if (nextIdx < 0) nextIdx = 0;
        currentIdx = nextIdx;

        stackedWidget->setCurrentWidget(m_pages.at(nextIdx));
    });

    connect(qrcode, &QRCode::backButtonPressed, this, [this, &currentIdx]() {
        currentIdx = 0;
        stackedWidget->setCurrentWidget(welcome);
        teleScouting->clear();
        autoScouting->clear();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::serializeData() {
    QStringList csv;
    csv << "Field,Value";
    csv << "Team Number," + QString::number(teamInfo->teamNumber());
    csv << "Match Number," + QString::number(teamInfo->matchNumber());
    csv << "Event Code," + teamInfo->eventCode();
    csv << "Auto Mobility," + QString::number(autoScouting->mobility());
    csv << "Auto Amp Pieces," + QString::number(autoScouting->ampPieces());
    csv << "Auto Speaker Pieces," + QString::number(autoScouting->speakerPieces());
    csv << "Tele Amp Pieces," + QString::number(teleScouting->ampPieces());
    csv << "Tele Speaker Pieces," + QString::number(teleScouting->speakerPieces());
    csv << "Tele Dropped Amp Pieces," + QString::number(teleScouting->droppedAmpPieces());
    csv << "Tele Dropped Speaker Pieces," + QString::number(teleScouting->droppedSpeakerPieces());
    csv << "Tele Trap Pieces," + QString::number(teleScouting->trapPieces());
    csv << "Tele Climb," + QString::number(teleScouting->climb());

    return csv.join("\n");
}
