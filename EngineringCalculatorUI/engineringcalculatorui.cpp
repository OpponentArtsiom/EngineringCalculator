#include "engineringcalculatorui.h"
#include "ui_engineringcalculatorui.h"
#include <QtMath>

EngineringCalculatorUI::EngineringCalculatorUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EngineringCalculatorUI)
{
    ui->setupUi(this);

    connect(ui->one,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->two,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->three,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->four,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->five,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->six,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->seven,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->eight,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->nine,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);
    connect(ui->zero,&QPushButton::clicked,this,&EngineringCalculatorUI::Digits_operation);

    connect(ui->backspace,&QPushButton::clicked,this,&EngineringCalculatorUI::Backspace);
    connect(ui->AC,&QPushButton::clicked,this,&EngineringCalculatorUI::AC);
    connect(ui->dot,&QPushButton::clicked,this,&EngineringCalculatorUI::Dot);
    connect(ui->plus_minus,&QPushButton::clicked,this,&EngineringCalculatorUI::Sign_change);
    connect(ui->percent,&QPushButton::clicked,this,&EngineringCalculatorUI::Percent);
    connect(ui->root,&QPushButton::clicked,this,&EngineringCalculatorUI::Root);
    connect(ui->square,&QPushButton::clicked,this,&EngineringCalculatorUI::Square);

    connect(ui->clearmemory,&QPushButton::clicked,this,&EngineringCalculatorUI::Clear_memory);
    connect(ui->readmemory,&QPushButton::clicked,this,&EngineringCalculatorUI::Read_memory);
    connect(ui->addmemory,&QPushButton::clicked,this,&EngineringCalculatorUI::Addition_in_memory);
    connect(ui->submemory,&QPushButton::clicked,this,&EngineringCalculatorUI::Subtraction_in_memory);

    connect(ui->sin,&QPushButton::clicked,this,&EngineringCalculatorUI::Sinus);
    connect(ui->cos,&QPushButton::clicked,this,&EngineringCalculatorUI::Cosine);
    connect(ui->tan,&QPushButton::clicked,this,&EngineringCalculatorUI::Tangent);
    connect(ui->asin,&QPushButton::clicked,this,&EngineringCalculatorUI::Arcsine);
    connect(ui->acos,&QPushButton::clicked,this,&EngineringCalculatorUI::Arccosine);
    connect(ui->atan,&QPushButton::clicked,this,&EngineringCalculatorUI::Arctangent);

    connect(ui->log,&QPushButton::clicked,this,&EngineringCalculatorUI::Logarithm);
    connect(ui->log_10,&QPushButton::clicked,this,&EngineringCalculatorUI::Decimal_logarithm);

    connect(ui->pi,&QPushButton::clicked,this,&EngineringCalculatorUI::PI);
    connect(ui->e,&QPushButton::clicked,this,&EngineringCalculatorUI::E);

    connect(ui->division,&QPushButton::clicked,this,&EngineringCalculatorUI::Math_operation);
    connect(ui->multiplication,&QPushButton::clicked,this,&EngineringCalculatorUI::Math_operation);
    connect(ui->subtraction,&QPushButton::clicked,this,&EngineringCalculatorUI::Math_operation);
    connect(ui->addition,&QPushButton::clicked,this,&EngineringCalculatorUI::Math_operation);
    connect(ui->equals,&QPushButton::clicked,this,&EngineringCalculatorUI::Equals);

    // ?????????????????????????? ?????? ???????????? + - * / ???????????????? ???? true ?????? false.
    ui->addition->setCheckable(true);
    ui->subtraction->setCheckable(true);
    ui->division->setCheckable(true);
    ui->multiplication->setCheckable(true);
}

EngineringCalculatorUI::~EngineringCalculatorUI()
{
    delete ui;
}

//________________?????????????? ????????????.______________//
void EngineringCalculatorUI::Digits_operation()
{
    {
        QPushButton *button = (QPushButton *) sender();

        if(ui->display->text().contains(".") && button->text() == "0")  // ???????????????????????????? ???????????????? ?????? ???????? ?????? ???? ?????????? ?????????? ?????????? ???????? ???????????? ?????????????????? ??????????
        {
            fixed_text = ui->display->text() + button->text();
        }
        else
        {
            all_numbers = (ui->display->text() + button->text()).toDouble();
            fixed_text = QString::number(all_numbers, 'g', 15);
        }

        ui->display->setText(fixed_text);
    }
}

//________________???????????????????????????? ????????????????: ???????????? ?????????? ?? ?????????? ?????????????????????????????? ??????????.______________//
void EngineringCalculatorUI::Math_operation()
{
    QPushButton *button = (QPushButton *) sender();
    num_first = ui->display->text().toDouble();
    ui->display->setText("");
/*
    if(ui->addition->isChecked())
    {
        ui->display->setText("+");
        ui->addition->setChecked(false);            // ???? ????????????????.
    }
    else if (ui->subtraction->isChecked())
    {
        ui->display->setText("-");
        ui->subtraction->setChecked(false);
    }

    else if (ui->multiplication->isChecked())
    {
        ui->display->setText("*");
        ui->multiplication->setChecked(false);
    }

    else if (ui->division->isChecked())
    {
        ui->display->setText("/");
        ui->division->setChecked(false);
    }
*/
    button->setChecked(true);
}

//________________???????????????????? ???????????????????????????? ????????????????.______________//
void EngineringCalculatorUI::Equals()
{
       num_second =ui->display->text().toDouble();
        if(ui->addition->isChecked())
        {
            result = num_first + num_second;
            fixed_text = QString::number(result, 'g', 15);
            ui->display->setText(fixed_text);
            ui->addition->setChecked(false);
        }

        else if(ui->subtraction->isChecked())
        {
            result = num_first - num_second;
            fixed_text = QString::number(result, 'g', 15);
            ui->display->setText(fixed_text);
            ui->subtraction->setChecked(false);
        }

        else if(ui->multiplication->isChecked())
        {
            result = num_first * num_second;
            fixed_text = QString::number(result, 'g', 15);
            ui->display->setText(fixed_text);
            ui->multiplication->setChecked(false);
        }

        else if(ui->division->isChecked())
        {
            if(num_second == 0) // ???????????????? ?????????????? ???? ????????.
            {
                ui->display->setText("0");
            }
            else
            {
                result = num_first / num_second;
                fixed_text = QString::number(result, 'g', 15);
                ui->display->setText(fixed_text);
            }
             ui->division->setChecked(false);
        }
}

//________________Backspace.______________//
void EngineringCalculatorUI::Backspace()
{
    QString text = ui->display -> text();
      text.chop(1);                           // chop() - ?????????????? ???? ??????????????????

      if (text.isEmpty())
      {
          text = "0";
      }

      ui->display -> setText(text);
}

//________________?????????????? ????????????.______________//
void EngineringCalculatorUI::AC()
{
    ui->display->setText("0");
}

//________________?????????? ????. ???????????????????????????? ??????????????????.______________//
void EngineringCalculatorUI::PI()
{
    ui->display->setText("3.1415926535897");
}

//________________?????????????????? ???????????????????????? ??????????????????. ???????????????????????????? ??????????????????.______________//
void EngineringCalculatorUI::E()
{
    ui->display->setText("2.7182818284590");
}

//________________??????????.______________//
void EngineringCalculatorUI::Dot()
{
    if(!(ui->display->text().contains('.')))        // contains() ???????????????? ?????????????? ??????????????
        ui->display->setText(ui->display->text() + ".");
}

//________________?????????? ??????????.______________//
void EngineringCalculatorUI::Sign_change()
{
    QPushButton *button = (QPushButton *) sender();

       if(button->text() == "+/-")
       {
           all_numbers = (ui->display->text()).toDouble();
           all_numbers = all_numbers * -1;
           fixed_text = QString::number(all_numbers, 'g', 15);
           ui->display->setText(fixed_text);
       }
}

//________________??????????????.______________//
void EngineringCalculatorUI::Percent()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "%")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________????????????.______________//
void EngineringCalculatorUI::Root()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "???x")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = std::sqrt(all_numbers);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________???????????????????? ?? ???????????? ??????????????.______________//
void EngineringCalculatorUI::Square()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "x??")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = std::pow(all_numbers, 2);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________?????????????? ????????????.______________//
void EngineringCalculatorUI::Clear_memory()
{
    sumInMemory = 0.0;
}

//________________???????????????? ?? ????????????.______________//
void EngineringCalculatorUI::Read_memory()
{
    ui->display->clear();
    ui->display->setText(QString::number(sumInMemory, 'g', 15));
}

//________________?????????????????? ?????????? ???? ???????????? ??.______________//
void EngineringCalculatorUI::Addition_in_memory()
{
    Equals();
    sumInMemory = sumInMemory + ui->display->text().toDouble();
}

//________________???????????? ?????????? ???? ???????????? ????.______________//
void EngineringCalculatorUI::Subtraction_in_memory()
{
    Equals();
    sumInMemory = sumInMemory - ui->display->text().toDouble();
}

//________________??????????.______________//
void EngineringCalculatorUI::Sinus()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "sin")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = std::sin(all_numbers * 3.141592653589793238462643 / 180);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________??????????????.______________//
void EngineringCalculatorUI::Cosine()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "cos")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = std::cos(all_numbers * 3.141592653589793238462643 / 180);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________??????????????.______________//
void EngineringCalculatorUI::Tangent()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "tan")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = std::tan(all_numbers * 3.141592653589793238462643 / 180);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________???????????????? ??????????.______________//
void EngineringCalculatorUI::Arcsine()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "asin")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = (std::asin (all_numbers) * 180 / 3.141592653589793238462643);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________???????????????? ??????????????.______________//
void EngineringCalculatorUI::Arccosine()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "acos")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = (std::acos (all_numbers) * 180 / 3.141592653589793238462643);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________???????????????? ??????????????.______________//
void EngineringCalculatorUI::Arctangent()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "atan")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = (std::atan (all_numbers) * 180 / 3.141592653589793238462643);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________????????????????.______________//
void EngineringCalculatorUI::Logarithm()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "log")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = std::log(all_numbers);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

//________________???????????????????? ????????????????.______________//
void EngineringCalculatorUI::Decimal_logarithm()
{
    QPushButton *button = (QPushButton *) sender();

    if(button->text() == "log(10)")

    {
        all_numbers = (ui->display->text()).toDouble();
        all_numbers = std::log10(all_numbers);
        fixed_text = QString::number(all_numbers, 'g', 15);
        ui->display->setText(fixed_text);
    }
}

