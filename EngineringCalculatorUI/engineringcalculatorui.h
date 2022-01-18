#ifndef ENGINERINGCALCULATORUI_H
#define ENGINERINGCALCULATORUI_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class EngineringCalculatorUI; }
QT_END_NAMESPACE

class EngineringCalculatorUI : public QWidget
{
    Q_OBJECT

public:
    EngineringCalculatorUI(QWidget *parent = nullptr);
    ~EngineringCalculatorUI();

private:
    Ui::EngineringCalculatorUI *ui;

public:
 double num_first;       //Глобальная переменная: первоое вводимое число.
 double num_second;      //Глобальная переменная: первоое вводимое число.
 double result;          //Глобальная переменная: результат арифметических операций.
 double all_numbers;     //Глобальная переменная: Все числа.
 QString fixed_text;     //Глобальная переменная: Для конвертации из Double в QString.
 double sumInMemory;     //Глобальная переменная: Для кнопок памяти.

private slots:

void Digits_operation();
void Math_operation();
void Equals();
void Backspace();
void AC();
void PI();
void E();
void Dot();
void Sign_change();
void Percent();
void Root();
void Square();
void Clear_memory();
void Read_memory();
void Addition_in_memory();
void Subtraction_in_memory();
void Sinus();
void Cosine();
void Tangent();
void Arcsine();
void Arccosine();
void Arctangent();
void Logarithm();
void Decimal_logarithm();

};
#endif // ENGINERINGCALCULATORUI_H
