
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cmath>

#include "global_macros.h"
#include "solar_system.h"

#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, protected solar_system
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Properties_Button_clicked();
    void Properties_View_Move();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_POS_X_INITIAL_valueChanged(double arg1);

    void on_POS_Y_INITIAL_valueChanged(double arg1);

    void on_VEL_X_INITIAL_valueChanged(double arg1);

    void on_VEL_Y_INITIAL_valueChanged(double arg1);

    void on_ACELERATION_X_valueChanged(double arg1);

    void on_ACELERATION_Y_valueChanged(double arg1);

    void on_MASA_valueChanged(double arg1);

    void Fisicas();

    void on_PERIODO_valueChanged(double arg1);

    void on_SIMULACION_VELOCIDAD_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

    QTimer *Properties_Timer;
    bool Properties_Pressed;
    int Properties_Counter;

    float maxvx, maxvy;

    void Set_Properties_Default();
    void Set_Text_Sun();

    void Combobox_text(short num);

    void calcular_fisicas(float Periodo, float Simulation_Speed);

    void aplicar_fisicas();

};

#endif // MAINWINDOW_H
