# project-lineyka
Данная программа преобразует данную бинарную линейку по задданым правилам перевода.

Правила пользования: 
Иммется возможность считывание исходных параметров из файла(пример файла прикреплён). Также возможно по заданным из консоли длине исходной строки и необходимому количеству выводимых строк случайно задать исходную линейку и правила перевода.

Data:
данные записываются без лишних пробелов

Первая строка: длина исходной линейки

Вторая строка: колличество выводимых строк

Третья строка: начальная строка

Четвёртая строка: правила перевода
0 0 0 -> ?
0 0 1 -> ?
0 1 0 -> ?
0 1 1 -> ?
1 0 0 -> ?
1 0 1 -> ?
1 1 0 -> ?
1 1 1 -> ?

В коде реалезована система поиска ошибок.
Программа может проверить на корректность введённые в data параметры.
Проверки: на корректность длины строк и кооличесва строк, совместимость длины исходной строки и полученой исходной строки, открылся ли вообще файл.
