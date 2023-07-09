import os
import hashlib
from Cryptodome.Cipher import AES

n = input("Введите для папки Passes: ")
m = int(input("Минимальная длина пароля: "))
s = int(input("Длина пароля: "))
os.mkdir(f'Results_{n}')
salt = b'SALT'
iterations = 100
found = False

decripted_data = bytearray.fromhex('F9E4641D212F33E7A7DA288135DA3C58'
                                   'A78A3762DA6A4441E6D963B973E2688E'
                                   'A28BF0730FFE92E3D17B22886F05D26F'
                                   '935E40CE90F39AEFDBBF5403C315C846')

for i in range(m, s + 1):
    with open(f'Passes_{n}/comb_{i}.txt', 'r') as f, open(f'Results_{n}/result_{i}.txt', 'w', encoding='utf-8') as f_result:
        total_lines = sum(1 for line in f)
        f.seek(0)
        for count, line in enumerate(f, 1):
            password = line.strip().encode()
            key = hashlib.pbkdf2_hmac('sha1', password, salt, iterations, dklen=16)
            decipher = AES.new(key, AES.MODE_ECB)
            encripted_data = decipher.decrypt(decripted_data)
            s = encripted_data.decode('UTF-8', errors='ignore')
            f_result.write(f"{s}\n")
            if "End data" in s:
                print(f"Пароль: {line.strip()}, Текст: {s}")
                found = True
                break

            percent = int(count / total_lines * 100)
            fill_length = int(percent / 2)
            empty_length = 50 - fill_length
            progress_bar = f"[{'=' * fill_length}{' ' * empty_length}] {percent}%"
            print(f'{i}' + progress_bar, end='\r')
    print('\n')
    if found:
        break
print("Готово!")
