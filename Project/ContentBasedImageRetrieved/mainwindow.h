#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QColor>
#include <QtCore>
#include <QProgressDialog>
#include "compare.h"

namespace Ui {
class MainWindow;
}

struct ImageInfo
{
    double ratioCompare;
    QString nameImage;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_btnBrowse_clicked();

    void on_btnCancel_clicked();

    void on_btnNext_clicked();

    void on_btnBack_clicked();

    void on_editDataPath_returnPressed();

    void on_btnDataBrowse_clicked();

    void on_listWidget_itemSelectionChanged();

    void on_editPath_returnPressed();

    void on_radioHist_clicked();

    void on_btnCompare_clicked();

    void on_listResult_itemSelectionChanged();

    void on_btnChange_clicked();

    void on_editPath_textChanged(const QString &arg1);

    void on_editDataPath_textChanged(const QString &arg1);

    void on_radioFeature_clicked();

private:
    Ui::MainWindow *ui;
    QString pathFile;
    QString pathDataFolder;
    int bin;
    int threshold;
    void onCompareHist();
    void onCompareFeature();
};

#endif // MAINWINDOW_H
