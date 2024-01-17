#include "MainWindow.h"

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
        notes,
        scales,
        qrcode
    };

    connect(nextButton, &QPushButton::released, this, [this]() mutable {
        int nextIdx = currentIdx + 1;
        if (nextIdx >= stackedWidget->count()) nextIdx = stackedWidget->count() - 1;
        currentIdx = nextIdx;

        stackedWidget->setCurrentWidget(m_pages.at(nextIdx));

        if (nextIdx == stackedWidget->count() - 1) {
            qrcode->setQRData(serializeData());
        }
    });

    connect(backButton, &QPushButton::released, this, [this]() mutable {
        int nextIdx = currentIdx - 1;
        if (nextIdx < 0) nextIdx = 0;
        currentIdx = nextIdx;

        stackedWidget->setCurrentWidget(m_pages.at(nextIdx));
    });

    connect(qrcode, &QRCode::backButtonPressed, this, [this]() mutable {
        currentIdx = 0;
        stackedWidget->setCurrentWidget(welcome);
        teleScouting->clear();
        autoScouting->clear();
        notes->clear();
        scales->clear();
    });
}

MainWindow::~MainWindow()
{
}

QString MainWindow::serializeData() {
    QStringList tsv;
    tsv << QString::number(teamInfo->teamNumber());
    tsv << QString::number(teamInfo->matchNumber());

    tsv << QString::number(autoScouting->mobility());
    tsv << QString::number(autoScouting->ampPieces());
    tsv << QString::number(autoScouting->speakerPieces());
    tsv << QString::number(autoScouting->neutralZone());
    tsv << QString::number(autoScouting->aStop());

    tsv << QString::number(teleScouting->ampPieces());
    tsv << QString::number(teleScouting->speakerPieces());
    tsv << QString::number(teleScouting->trapPieces());

    tsv << QString::number(teleScouting->spotlights());
    tsv << QString::number(teleScouting->climb());
    tsv << QString::number(teleScouting->defense());
    tsv << QString::number(teleScouting->defended());

    tsv << QString::number(scales->driver());
    tsv << QString::number(scales->defense());
    tsv << QString::number(scales->speed());
    tsv << QString::number(scales->tippiness());
    tsv << QString::number(scales->teamwork());

    tsv << notes->notes().replace('\n', "; ");

    return tsv.join("\t");
}
