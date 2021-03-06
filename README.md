# Виртуальная машина MMIX

Эмуляция работы процессора MMIX, описанного в книге Д. Кнута "Искусство программирования, том 1, выпуск 1. MMIX – RISC-компьютер нового тысячелетия", на языке C++.
<br><br>

<strong>Виртуальная машина</strong> — программная и/или аппаратная система, эмулирующая  аппаратное обеспечение некоторой платформы (target) и исполняющая программы для target-платформы на host-платформе или виртуализирующая некоторую платформу и создающая на ней среды, изолирующие друг от друга программы и даже операционные системы.

<strong>RISC</strong> — архитектура процессора, в котором быстродействие увеличивается за счёт упрощения инструкций, чтобы их декодирование было более простым, а время выполнения — меньшим.<br>
<strong>MMIX</strong> является 64-битовым RISC-компьютером, содержащим 256 регистров общего назначения и 64-битовое адресное пространство.

<strong>Интерпретатор</strong> — это программная модель исполнителя команд абстрактной (виртуальной) машины.<br>
<strong>Загрузчик</strong> — это программа, выполняющая загрузку массива слов (программ и данных) с внешнего устройства в память компьютера.<br>
Программа для виртуальной машины (вместе с данными) хранится в файле и перед интерпретацией считывается в память. Затем интерпретатор начинает выполнять команды, выбирая их из памяти. <br>
Загружаемый в память массив слов может содержать команды, вещественные числа, целые числа и должен заканчиваться маркером конца.<br>
Массив слов представляет собой текстовый файл, его нужно набрать в текстовом редакторе. 

<strong>Подробная документация проекта, включая все диаграммы, алгоритмы, описание всех классов и комманд процессора, находится в файле document.pdf</strong>

# Пример программы для процессора MMIX
<pre>
a 400			// устанавливаем начало программы в памяти
c E3000190		// $0 = 400 (начало программы)
c F000001C		// ---------тут начинается подпрограмма ----------
c E3020001		// $2 = 1
c 21030301		// $3 += 1
c 18020203		// $2 *= $3
c 30040301		// $4 = ($3>$1) - ($3<$1), т.е. $4 будет = -1, если $3<$1
c 4104000C		// BNB - переход на 12 байт вверх (на 3 команды)
c 9F050500		// возвращаемся туда, откуда пришли --------------
c E3010005		// $1 = 5 (функция возвратит 5! = 120)
c 9F050008		// вызываем подпрограмму и сохраняем в $5 IP для возврата
c 21000200		// $0 = $2 + 0 (записываем в $0 результат)
c F9000000		// конец программы
</pre>
Больше примеров можно найти в папке <strong>examples</strong>
