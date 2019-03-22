#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    QPalette palette = ui->lblImage->palette();
    palette.setColor(ui->lblImage->backgroundRole(),Qt::gray);
    ui->lblImage->setPalette(palette);

    ui->btnBack->setEnabled(false);
    ui->btnNext->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_editPath_returnPressed()
{
    ui->lblImage->setPixmap(NULL);
    pathFile = ui->editPath->text();
    QPixmap image(pathFile);

    if(!image.isNull())
    {
        ui->lblImage->setScaledContents(true);
        ui->lblImage->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        ui->lblImage->setPixmap(image);
    }
    else
    {
        QMessageBox::information(this,"Warning","Your Path is not existed !!!");
    }
}

void MainWindow::on_btnBrowse_clicked()
{
    ui->lblImage->setPixmap(NULL);
    ui->editPath->setText("");

    pathFile = QFileDialog::getOpenFileName(
                this,"Open Image File",QDir::currentPath(),
                "All file (*.*);; JPG Image (*.jpg);; PNG Image (*.png)");
    QPixmap image(pathFile);
    if(!image.isNull())
    {
        ui->lblImage->setScaledContents(true);
        ui->lblImage->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        ui->lblImage->setPixmap(image);
        ui->editPath->setText(pathFile);
    }
    else
    {
        QMessageBox::information(this,"Warning","Your Path is not existed !!!");
    }
}

void MainWindow::on_btnCancel_clicked()
{
    destroy(true,true);
}

void MainWindow::on_btnNext_clicked()
{
    int curr = ui->stackedWidget->currentIndex();
    curr++;

    if(curr > 0)
        ui->btnBack->setEnabled(true);

    if(ui->editDataPath->text().isEmpty() && curr == 1)
        ui->btnNext->setEnabled(false);
    else if(curr == 2)
        ui->btnNext->setEnabled(false);
    else
        ui->btnNext->setEnabled(true);

    ui->stackedWidget->setCurrentIndex(curr);
}

void MainWindow::on_btnBack_clicked()
{
    int curr = ui->stackedWidget->currentIndex();
    curr--;
    if(curr == 0)
        ui->btnBack->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(curr);
}

void MainWindow::on_editDataPath_returnPressed()
{
    ui->listWidget->clear();
    pathDataFolder = ui->editDataPath->text();

    QDir directory(pathDataFolder);

    if(directory.exists())
    {

        QStringList image = directory.entryList(
                    QStringList() << "*.jpg" << "*.JPG" <<"*.PNG" << "*.png",
                    QDir::Files);

        QString pathImage;

        foreach (pathImage, image)
        {
            ui->listWidget->addItem(pathImage);
        }
        ui->listWidget->setCurrentRow(0);
    }
    else
        QMessageBox::information(this,"Warning","Your Path is not existed !!!");
}

void MainWindow::on_btnDataBrowse_clicked()
{
    ui->listWidget->clear();

    pathDataFolder = QFileDialog::getExistingDirectory(
                this,"Choose Data Directory",QDir::currentPath(),
                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QDir directory(pathDataFolder);

    if(directory.exists())
    {
        QStringList image = directory.entryList(
                    QStringList() << "*.jpg" << "*.JPG" <<"*.PNG" << "*.png",
                    QDir::Files);

        QString pathImage;

        foreach (pathImage, image)
        {
            ui->listWidget->addItem(pathImage);
        }
        ui->listWidget->setCurrentRow(0);
        ui->editDataPath->setText(pathDataFolder);
    }
    else
        QMessageBox::information(this,"Warning","Your Path is not existed !!!");
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    QString pathImage = ui->listWidget->currentItem()->text();
    pathImage = pathDataFolder + "/" + pathImage;
    QPixmap image(pathImage);
    ui->lblImageView->setScaledContents(true);
    ui->lblImageView->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->lblImageView->setPixmap(image);
}


void MainWindow::on_radioHist_clicked()
{
    bin = QInputDialog::getInteger(this,"Choose Bin Number","Bin Number: ",1,1,255);
    ui->lblAdditional->setText("Bin number: " + QString::number(bin));
}

bool itemLessThan(const ImageInfo item1, const ImageInfo item2)
{
    return item1.ratioCompare < item2.ratioCompare;
}

void MainWindow::onCompareHist()
{
    QString pathImageData;
    QList<ImageInfo> list;
    ImageInfo temp;

    int numData = ui->listWidget->count();
    for(int i =0; i < numData;i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        pathImageData = pathDataFolder + "/" + item->text();
        temp.ratioCompare = compareImageHist(pathFile,pathImageData,bin);
        temp.nameImage = item->text();
        list.append(temp);
    }

    qSort(list.begin(),list.end(),itemLessThan);

    foreach(temp,list)
    {
        QString pathImageData = pathDataFolder + "/" + temp.nameImage;
        ui->listResult->addItem(temp.nameImage);
    }
}

void MainWindow::onCompareFeature()
{
    QString pathImageData;
    QList<ImageInfo> list;
    ImageInfo temp;

    int numData = ui->listWidget->count();
    for(int i =0; i < numData;i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        pathImageData = pathDataFolder + "/" + item->text();
        temp.ratioCompare = compareImageFeature(pathFile,pathImageData,threshold);
        temp.nameImage = item->text();
        list.append(temp);
    }

    qSort(list.begin(),list.end(),itemLessThan);

    foreach(temp,list)
    {
        QString pathImageData = pathDataFolder + "/" + temp.nameImage;
        ui->listResult->addItem(temp.nameImage);
    }

}

void MainWindow::on_btnCompare_clicked()
{
    ui->listResult->clear();
    if(ui->radioHist->isChecked())
        onCompareHist();
    else if(ui->radioFeature->isChecked())
        onCompareFeature();

    ui->listResult->setCurrentRow(0);
}

void MainWindow::on_listResult_itemSelectionChanged()
{
    QString pathImage = ui->listResult->currentItem()->text();
    pathImage = pathDataFolder + "/" + pathImage;
    QPixmap image(pathImage);
    ui->lblImageResult->setScaledContents(true);
    ui->lblImageResult->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->lblImageResult->setPixmap(image);
}

void MainWindow::on_btnChange_clicked()
{
    if(ui->radioHist->isChecked())
    {
        bin = QInputDialog::getInteger(this,"Choose Bin Number","Bin Number: ",1,1,255);
        ui->lblAdditional->setText("Bin number: " + QString::number(bin));
    }
    else if(ui->radioFeature->isChecked())
    {
        threshold = QInputDialog::getInteger(this,"Choose Threshold Number","Threshold: ",100,1,200);
        ui->lblAdditional->setText("Threshold number: " + QString::number(threshold));
    }

}


void MainWindow::on_editPath_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
        ui->btnNext->setEnabled(false);
    else
        ui->btnNext->setEnabled(true);
}

void MainWindow::on_editDataPath_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
        ui->btnNext->setEnabled(false);
    else
        ui->btnNext->setEnabled(true);
}

void MainWindow::on_radioFeature_clicked()
{
    threshold = QInputDialog::getInteger(this,"Choose Threshold Number","Threshold: ",100,1,200);
    ui->lblAdditional->setText("Threshold number: " + QString::number(threshold));
}
