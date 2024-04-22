import itertools
import os
from math import factorial
from tqdm import tqdm

s = input("Введите пароль: ")
n = input("Введите имя: ")
min_length = int(input("Минимальная длина: "))
max_length = int(input("Максимальная длина: "))

# Создаем директорию для хранения файлов с комбинациями
directory = f'Passes_{n}'
os.makedirs(directory, exist_ok=True)

# Вычисляем общее количество комбинаций для прогресс бара
total_combinations = 0
for length in range(min_length, max_length + 1):
    total_combinations += factorial(len(s)) // factorial(len(s) - length)

# Генерируем и записываем комбинации различной длины без повторяющихся символов
for length in range(min_length, max_length + 1):
    with open(f'{directory}/comb_{length}.txt', 'w') as file:
        combinations = itertools.permutations(s, length)
        with tqdm(total=total_combinations, desc=f'Генерация комбинаций длины {length}', unit='комбинации') as pbar:
            for combo in combinations:
                file.write("".join(combo) + "\n")
                pbar.update(1)

print("Все пароли сгенерированы и сохранены в соответствующие файлы.")
