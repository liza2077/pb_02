# Объектно-ориентированное программирование

### Работа с контейнерами

>  Внимание! Исходные тексты программ могут содержать любое количество ошибок, их поиск и исправление составляют часть упражнения.

## Краткие теоретические сведения

**Предикаты**, применяемые к элементам контейнера, позволяют обнаружить элементы с заданными (предикатом) свойствами.
Типовое применение: перебор элементов контейнера, для std::vector --- по индексу элемента и применение предиката к каждому элементу.

Контейнеры могут быть результатом, возвращаемым функцией.
Пример --- отбор из перечня студентов тех, чьи имена (фамилии) начинаются на букву 'А'.

Чтобы без необходимости не увеличивать объем используемой программой памяти отбираемые элементы могут (а зачастую --- должны) удаляться из исходного контейнера.
Удаление элементов выполняется методом (функцией-членом) `erase`.
Параметром `erase` должен быть **итератор** --- особый объект, указывающий на элемент контейнера.

Итератор на элемент может быть получен с использованием индекса элемента в векторе, как результат сложения: `cont.begin() + i`, где `cont.begin()` --- итератор, указывающий на первый элемент контейнера, а `i` --- индекс текущего элемента.

Итератор `cont.begin()` уже использовался в программе в качестве одного из параметров функции `sort()` стандартной библиотеки.

## Задание

1. Добавить к модулю student_info функцию печати итоговой оценки студента с параметрами `std::string` --- имя студента, `std::size_t` --- ширина колонки для имени и `double` --- итоговая оценка.
В качестве основы использовать фрагменты кода, находящиеся в функции main.


Для тестирования программы используйте команду `cmake --build build --target test`.
Для каждой записи из файла `tests/studs.txt` должен выполняется расчет итоговой оценки.


## Запуск программы

Запуск выполняется стандартным способом, из терминала, открытого в папке проекта.

Название программы (`ch06`), определено в файле проекта CMakeLists.txt

`build/ch06`


## Инструментарий для сборки проекта

1. `cmake`
1. `make`
1. `g++ (gcc)`
1. `git`


## Настройка и сборка проекта

Настройка проекта (build --- название папки для артефактов сборки, можно выбирать произвольно):

`cmake -B build`

Сборка проекта:

`cmake --build build`
