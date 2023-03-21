## На случай ошибок при сборке:
``` bash
apt-get install alsa-utils
pip3 install pyxhook
sudo apt install portaudio19-dev
```

## Сборка:
* Перед установкой создайте бота в @BotFather
``` bash
pip3 install --user -r requirements.txt
python3 main.py --InitApiToken `токен бота`
python3 main.py --TokenCreate --name root --perms "*"
python3 main.py
```

## Начало работы:
* В созданном боте:
``` bash
/authorized `сгенерированный токен`
```

## Запись в автозагузку:
``` bash
python3 main.py --InstallAgent
```

## Список команд:

``` bash
python3 main.py -h
```

