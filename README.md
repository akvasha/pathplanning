# pathplanning
Программный проект "Нахождение кратчайших путей" студента БМПИ171-1 Кваша Антон

##Формат входных данных
На вход подается xml-файл. Путь к файлу указывается первым аргументом программы.
Пример входного файла находится в репозитории: `example.xml`

Во входном файле выделяются 3 основных раздела:
1) map - раздел, содержащий информацию о карте
2) algorithm - раздел, сожержащий информацию об используемом алгоритме
3) options - раздел, отвещающий за дополнительные параметры

Ниже представлен список тегов, используемых в разделах входного файла.

| Тег           | Описание тега                                                       |
|---------------|---------------------------------------------------------------------|
| root          | Глобальный тег, в котором содержутся все остальные теги             |
| map           | Тег, описывающий карту                                              |
| weidth        | Ширина карты                                                        |
| height        | Высота карты                                                        |
| cellsize      | Масштаб карты                                                       |
| grid          | Тег, указывающий на начало карты                                    |
| row           | Описание строки карты                                               |
| startx        | Стартовая координата по x                                           |
| starty        | Стартовая координата по y                                           |
| finishx       | Конечная координата по x                                            |
| finishy       | Конечная координата по y                                            |
| algorithm     | Описание алгоритма поиска пути                                      |
| searchtype    | Тип алгоритма поиска                                                |
| metrictype    | Тип метрики пространства                                            |
| breakingties  | Тип сравнения вершин при равенстве f-value                          |
| allowdiagonal | Возможность прокладывать путь по диагонали                          |
| cutcorners    | Возможность срезать углы                                            |
| allowsqueeze  | Возможность проходить по диагонали между двумя препятствтиями       |
| options       | Описание дополнительных параметром программы                        |
| logpath       | Путь сохранения файла вывода                                        |
| logfilename   | Имя сохраняемого файла с результатами                               |
| loglevel      | Вербозность вывода алгоритма построения                             |

##Формат выходных данных
На выходе получается xml-файл содержащий информацию о результате работы алгоритма. В нем содержатся все теги, использованные во входном файле, но также и несколько уникальных.
Ниже представлен список тегов, используемых только в разделах выходного файла.

| Тег           | Описание тега                                                       |
|---------------|---------------------------------------------------------------------|
| mapfilename   | Имя выходного файла                                                 |
| summary       | Информация о результате работы алгоритма                            |
| path          | Карта, содержащая путь, найденый алгоритмом, если таковой имеется   |
| lplevel       | Описание l-path                                                     |
| hplevel       | Описание h-path                                                     |

##Сборка и запуск
Проект может быть собран с использованием qmake и cmake.
Сборка проекта с помощью cmake производится командой
```
cmake CMakeLists.txt && make
```
Результатом исполнения данной команды будет бинарный файл `pathplanning`