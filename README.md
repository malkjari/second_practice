# mysyslog

mysyslog - это проект для ведения журналов, предоставляющий библиотеку для логирования в различных форматах, таких как текст и JSON, а также клиент и демон для использования этой библиотеки.

## Структура проекта

mysyslog/
|-- libmysyslog/
| |-- src/
| | |-- mysyslog.c
| |-- include/
| | |-- mysyslog.h
| |-- Makefile
|-- libmysyslog-text/
| |-- src/
| | |-- text_driver.c 
| |-- include/ 
| | |-- text_driver.h 
| |-- Makefile 
|-- libmysyslog-json/
| |-- src/
| | |-- json_driver.c
| |-- include/
| | |-- json_driver.h
| |-- Makefile
|-- libmysyslog-client/ 
| |-- src/ 
| | |-- client.c 
| |-- include/ 
| | |-- client.h 
| |-- Makefile 
|-- libmysyslog-daemon/
| |-- src/
| | |-- daemon.c
| |-- include/
| | |-- daemon.h
| |-- Makefile
|-- Makefile 
|-- README.md


## Составные части

### libmysyslog
Основная библиотека для логирования, поддерживающая различные форматы и уровни логирования.

### libmysyslog-text
Плагин для libmysyslog, обеспечивающий логирование в текстовом формате.

### libmysyslog-json
Плагин для libmysyslog, обеспечивающий логирование в формате JSON.

### libmysyslog-client
Клиентское приложение, использующее libmysyslog для логирования сообщений.

### libmysyslog-daemon
Демон, использующий libmysyslog для автоматического логирования с конфигурацией через файл.

## Установка

### Сборка всех компонентов

1. Клонируйте репозиторий:

    git clone https://github.com/ваш_пользователь/myysyslog.git
    cd mysyslog


2. Соберите все компоненты:

    make all


3. Соберите deb-пакеты для всех компонентов:

    make deb


4. Создайте локальный репозиторий:

    make repo


## Установка deb-пакетов

1. Установите все deb-пакеты:

    sudo dpkg -i libmysyslog/*.deb libmysyslog-text/*.deb libmysyslog-json/*.deb libmysyslog-client/*.deb libmysyslog-daemon/*.deb


2. Установите метапакет для установки всех компонентов:

    sudo dpkg -i mysyslog-meta.deb


## Использование

### mysyslog-client

Используйте клиент для логирования сообщений:
mysyslog-client -m "Ваше сообщение" -l <уровень> -d <драйвер> -f <формат> -p <путь>

Где:
- `<уровень>`: уровень логирования (DEBUG=0, INFO=1, WARN=2, ERROR=3, CRITICAL=4)
- `<драйвер>`: драйвер логирования (TEXT=0, JSON=1)
- `<формат>`: формат логирования (PLAIN=0, JSON_FORMAT=1)
- `<путь>`: путь к файлу для логирования

### mysyslog-daemon

1. Сконфигурируйте демон через файл `/etc/mysyslog/mysyslog.cfg`:

    path=/var/log/mysyslog.log
    driver=0
    format=0

2. Запустите демон через systemd:

    sudo systemctl start mysyslog-daemon
    sudo systemctl enable mysyslog-daemon


