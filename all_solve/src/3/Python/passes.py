import itertools
import os

s = input("Введите пароль: ")
chars = set(s)
n = input("Введите имя: ")
b = int(input("Минимальная длина: "))
os.mkdir(f'Passes_{n}')

for i in range(b, len(s) + 1):
	with open(f'Passes_{n}/comb_{i}.txt', 'w') as file:
		for combo in itertools.permutations(chars, i):
			file.write("".join(combo) + "\n")
print("Все пароли сгенерированы")
