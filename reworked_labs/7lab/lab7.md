МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ Федеральное государственное автономное образовательное учреждение высшего образования "КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО" ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ Кафедра компьютерной инженерии и моделирования



### Отчёт по лабораторной работе № 7 по дисциплине "Программирование"



студента 1 курса группы ПИ-б-о-192(1)
Кононова Алексея Геннадьевича
направления подготовки 09.03.04 "Программная инженерия"

<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>Чабанов В.В.</td>
<td>(оценка)</td>
</table>

<br/><br/>

------

## Цель:

изучить основные возможности создания и отладки программ в IDE Qt Creator 

## Выполнение заданий:

#### 1.Как создать консольное приложение С++ в IDE Qt Creator без использования компонентов Qt?

Нажимаем раздел "Начало", далее Проекты -> Создать, и в диалоговом окне мы выбираем нужные пункты. Диалоговое окно показано на рисунке 1.
![]( https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/1.jpg )
Рис. 1 - Диалоговое окно

#### 2.Как изменить цветовую схему (оформление) среды?

Заходим в раздел "Параметры", далее в фильтре "Среда" выбираем нужные параметры. Фильтр "Среда" показан на рисунке 2.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/2.jpg)
Рис. 2 - Фильтр "Среда"

#### 3.Как закомментировать/раскомментировать блок кода средствами Qt Creator?

Выделяем наш код и правой кнопкой мыши нажимае по выделенной области. Далее выбираем в меню пункт комментирования. Пунк комментирования показан на рисунке 3.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/3.jpg)
Рис. 3 - Пунк комментирования

#### 4. Как открыть в проводнике Windows папку с проектом средствами Qt Creator?

В инспекторе проекта нажимаем правой кнопкой мыши по любому файлу и в списке выбираем "Показать в проводнике". Список показан на рисунке 4.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/4.jpg)
Рис. 4 - Список

#### 5. Какое расширение файла-проекта используется Qt Creator?

Расширение файла проекта - ".pro". Файл-проект показан на рисунке 5.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/5.jpg)
Рис. 5 - Файл-проект

#### 6. Как запустить код без отладки?

Для запуска кода без отладки нам нужно нажать на зеленый треугольник. Треугольник показан на рисунке 6.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/6.jpg)
Рис. 6 - Треугольник

#### 7. Как запустить код в режиме отладки?

Для запуска код в режиме отладки нужно нажать на треугольник с жуком. Треугольник с жуком показан на рисунке 7.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/7.jpg)
Рис. 7 - Треугольник с жуком

#### 8. Как установить/убрать точку останова (breakpoint)?

Нажимаем правой кнопкой мыши по нумерованной строке кода и получаем список с остановом. Список с остановом показан на рисунке 8.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/8.jpg)
Рис. 8 - Список с остановом

#### 9. Создайте программу со следующим кодом:

```c++
#include <iostream>
int main() {
    int i;
    double d;
    i = 5;
    d = 5;
    std::cout << i << d;
    return 0;
}
```
* Переключитесь в конфигурацию сборки «Отладка»;
* Установите breakpoint на 5, 6 и 7 строках;
* Запустите приложение щелкнув по кнопке с изображением жука .
* Используйте эту же кнопку для перехода к следующей точке останова;
* Какое значение содержит переменная i в 5й строке?
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/9.1.jpg)
Рис. 9 - Значение i в 5й строке
* Какое значение содержит переменная d в 6й строке?
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/9.2.jpg)
Рис. 10 - Значение d в 6й строке
* Какие значение содержатся в переменных i и  d в 7й строке?
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/9.3.jpg)
Рис. 11 - Значения i и d в 7й строке
* Совпадают ли эти значения с теми, что вы получали в MSVS для соответствующих типов? Да, но есть нюансы: 
1) По итогу значение 5 в 7й строке у 'i' и 'd', только в MSVS у 'd' остается формат на выводе с плавающей точкой, а у QT как целочисленное 
2) Результаты в точке останова 5й и 6й строк - полностью отличаются от MSVS, если мы заведомо не присвоили напрямую конкретное значение

#### 10. Закройте проект и перейдите на вкладку «Начало» => «Примеры»;

Результат показан на рисунке 12.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/10.jpg)
Рис. 12 - Результат

#### 11. Выберите проект «Calculator Form Example». Для этого можно воспользоваться строкой поиска;

Выбранный проект показан на рисунке 13.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/11.jpg)
Рис. 13 - Выбранный проект

#### 12. Изучите (по желанию) описание проекта в открывшемся окне;

Описание проекта показано на рисунке 14.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/12.jpg)
Рис. 14 - Описание проекта

#### 13. Сейчас вы находитесь на вкладке «Проекты». Выберите комплект сборки.

Комплект сборки показан на рисунке 15.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/13.jpg)
Рис. 15 - Комплект сборки

#### 14. Перейдите на вкладку «Редактор» и запустите сборку проекта;

Вкладка "Редактор" и запущенная сборка показана на рисунке 16.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/14.jpg)
Рис. 16 - Вкладка "Редактор" и запущенная сборка

#### 15. В инспекторе проекта выберите файл «main.cpp». В этом файле установите курсор на слово «show» в строке calculator.show(); и нажмите F1. Изучите справочную информацию. Таким же образом можно получить справку по любому объекту/методу/полю доступному в Qt;

Справочная информация показана на рисунке 17.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/15.jpg)
Рис. 17 - Справочная информация

#### 16. В инспекторе проекта выберите файл «Формы» => «calculatorform.ui» и дважды счёлкните ЛКМ;

Вкладка "Дизайн" показана на рисунке 18.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/16.jpg)
Рис. 18 - Вкладка "Дизайн"

#### 17.Вы попали на вкладку «Дизайн». На форме замените английский текст на русский. Пересоберите проект.

Замененный текст и собранный проект показан на рисунке 19.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/7lab/images/17.jpg)
Рис. 19 - Замененный текст и собранный проект

------

## Вывод

я изучил основные возможности создания и отладки программ в IDE Qt Creator