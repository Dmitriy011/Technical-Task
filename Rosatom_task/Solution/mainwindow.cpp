#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "rectangle.h"
#include "cutting_task.h"

#include <QDebug>
#include <QRandomGenerator>
#include <vector>

void parse_QString_to_Rectangles(std::vector<Rectangle>& rectangles, QString str)
{
    QStringList pairs = str.split("; ");

    for (const QString& pair : pairs)
    {
        QStringList values = pair.split(" ");
        Rectangle tmp_rectangle (values[0].toInt(), values[1].toInt());
        rectangles.push_back(tmp_rectangle);
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "length width" << "count");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_rectangles(std::vector<Rectangle>& rectangles, int lenght_main, int width_main, int count_list)
{
    scene.clear();
    scene.setSceneRect(0, 0, width_main, lenght_main);

    QGraphicsRectItem *rect = scene.addRect(0, 0, width_main, lenght_main);
    rect->setBrush(Qt::NoBrush);
    rect->setPen(QPen(Qt::black));

    for (int i = 0; i < count_list; ++i)
    {
        QGraphicsRectItem *rect_first = scene.addRect(
            rectangles[i].x,
            rectangles[i].y,
            rectangles[i].is_rotated ? rectangles[i].get_length() : rectangles[i].get_width(),
            rectangles[i].is_rotated ? rectangles[i].get_width() : rectangles[i].get_length()
            );

        rect_first->setBrush(Qt::NoBrush);
        rect_first->setPen(QPen(Qt::black));
    }

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::on_pushButton_clicked()
{
    int lenght_main = ui->lineEdit->text().toInt();
    int width_main = ui->lineEdit_2->text().toInt();

    std::vector<Rectangle> rectangles;
    int amount = 0;

    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        if(ui->tableWidget->item(i, 0) == nullptr)
        {
            continue;
        }

        if(ui->tableWidget->item(i, 1) == nullptr)
        {
            continue;
        }

        QTableWidgetItem *param = ui->tableWidget->item(i, 0);
        QTableWidgetItem *count_q = ui->tableWidget->item(i, 1);
        int count = count_q->text().toInt();

        for (int j = 0; j < count; ++j)
        {
            QString tmp_val = param->text();

            QStringList values = tmp_val.split(" ");
            Rectangle tmp_rectangle (values[0].toInt(), values[1].toInt(), width_main + 200);
            rectangles.push_back(tmp_rectangle);
            amount++;
        }
    }

    if(amount >= 1)
    {
        int count_of_manufactured = 0;

        calculate_coord_rectangles(rectangles, lenght_main, width_main, rectangles.size(), count_of_manufactured);
        ui->label_2->setText(QString::number(count_of_manufactured));

        print_rectangles(rectangles, lenght_main, width_main, rectangles.size());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
}


void MainWindow::on_pushButton_3_clicked()
{
    int count_list = 3;
    int lenght_main = 100;
    int width_main = 50;

    int count_of_manufactured = 0;

    std::vector<Rectangle> rectangles;

    parse_QString_to_Rectangles(rectangles, ui->test1_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_2->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}


void MainWindow::on_pushButton_4_clicked()
{
    int count_list = 4;
    int lenght_main = 100;
    int width_main = 50;

    int count_of_manufactured = 0;

    std::vector<Rectangle> rectangles;

    parse_QString_to_Rectangles(rectangles, ui->test2_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_2->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}


void MainWindow::on_pushButton_5_clicked()
{
    int count_list = 5;
    int lenght_main = 100;
    int width_main = 50;

    int count_of_manufactured = 0;

    std::vector<Rectangle> rectangles;

    parse_QString_to_Rectangles(rectangles, ui->test3_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_2->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}


void MainWindow::on_pushButton_6_clicked()
{
    int count_list = 7;
    int lenght_main = 100;
    int width_main = 50;

    std::vector<Rectangle> rectangles;

    int count_of_manufactured = 0;

    parse_QString_to_Rectangles(rectangles, ui->test4_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_2->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}


void MainWindow::on_pushButton_7_clicked()
{
    int count_list = 6;
    int lenght_main = 100;
    int width_main = 50;

    std::vector<Rectangle> rectangles;

    int count_of_manufactured = 0;

    parse_QString_to_Rectangles(rectangles, ui->test5_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_2->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}
