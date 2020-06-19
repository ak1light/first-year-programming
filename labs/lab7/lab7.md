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

1.  изучить основные возможности создания и отладки программ в IDE Qt Creator 

## Ход работы

#### 1.Как создать консольное приложение С++ в IDE Qt Creator без использования компонентов Qt.<br/>

1. Запускаем приложение QT Creator. 
	Необходимо открыть QT Creator, затем:
**Проекты → Создать → Проект без QT → Приложение на языке с++.** 
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/1.jpg)
Рис. 1 - Проекты

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/2.jpg)
Рис. 2 - Создать

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/3.jpg)
Рис. 3 - Проект без QT -> Приложение на языке C++

#### 2.Как изменить цветовую схему (оформление) среды.

Необходимо нажать на меню **Инструменты → Параметры → Среда**, после чего выбирать темы.

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/4.jpg)
Рис. 4 - Цветовые схемы

#### 3.Как закомментировать/раскомментировать блок кода средствами QT Creator. 

 С помощью сочетания клавиш **CTRL + /** 

#### 4. Как открыть в проводнике Windows папку с проектом средствами QT Creator.

Необходимо нажать на любой файл в проекте правой кнопкой мыши → показать в проводнике.

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/5.jpg)
Рис. 5 - Открытие папки с проектом

#### 5. Какое расширение файла-проекта используется QT Creator.

***.pro***

#### 6. Как запустить код без отладки.

Комбинация клавиш ***CTRL + R*** или знак зелёной стрелочки.

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/6.jpg)
Рис. 6 - Запуск без отладки

#### 7. Как запустить код в режиме отладки

Клавиша ***F5*** или стрелочка с жуком

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/7.jpg)
Рис. 7 - Запуск проекта с отладкой

#### 8. Как установить/убрать точку останова (breakpoint).

Клавиша ***F9*** <br/> либо ПКМ по серому полю нужно строки.

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/8.jpg)
Рис. 8 - Точка останова

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

* Переключитесь в конфигурацию сборки "Отладка"; 

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/9.jpg)
Рис. 9 - "Отладка"

* Установите breakpoint на 5, 6 и 7 строках; 
* Запустите приложение щелкнув по кнопке с изображением жука; 
* Используйте эту же кнопку для перехода к следующей точке останова; 
* Какое значение содержит переменная i в 5й строке?

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/10.jpg)
Рис. 10 - Значение i

* Какое значение содержит переменная d в 6й строке? 

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/11.jpg)
Рис. 11 - Значение d

* Какие значение содержатся в переменных i и  d в 7й строке?

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/12.jpg)
Рис. 12 - Значения i и d

* Совпадают ли эти значения с теми, что вы получали в MSVS для соответствующих типов? Да.

#### 10. Выбираем проект «Calculator Form Example». 

#### 11. В инспекторе проекта выбираем файл «main.cpp». В этом файле устанавливаем курсор на слово «show» в строке calculator.show(); и нажимаем **F1**. 

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/13.jpg)
Рис. 13 - Справка

#### 12. Через файл «calculatorform.ui» мы попадаем во вкладку "Дизайн".

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/14.jpg)
Рис. 14 - Дизайн

Заменим текст на русский и пересоберём проект. 

![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/labs/lab7/images/15.jpg)
Рис. 15 - Сборка 

------

## Вывод

я изучил основные возможности создания и отладки программ в IDE Qt Creator