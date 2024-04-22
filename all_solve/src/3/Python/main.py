import os
import hashlib
from Cryptodome.Cipher import AES
from tqdm import tqdm

n = input("Введите название папки Passes: ")
m = int(input("Минимальная длина пароля: "))
s = int(input("Длина пароля: "))
results_dir = f'Results_{n}'
os.mkdir(results_dir)  # Создание директории для результатов

salt = b'SALT'
iterations = 123
decripted_data = bytearray.fromhex('CA9E522E36D2B076AFA26C926074C3A4'
                                   'E822773BC45413870D88489D97BA4FE5'
                                   'C0911F9B8944723D2B74BA54633036E3'
                                   'D271DD0AF55DAFECA78FCA3AC0F9AAEE')

found = False

for i in range(m, s + 1):
    input_filename = f'Passes_{n}/comb_{i}.txt'
    output_filename = f'{results_dir}/result_{i}.txt'

    with open(input_filename, 'r', encoding='utf-8') as f, open(output_filename, 'w', encoding='utf-8') as f_result:
        for line in tqdm(f, desc=f'Processing comb_{i}.txt'):
            password = line.strip().encode()
            key = hashlib.pbkdf2_hmac('sha1', password, salt, iterations, dklen=16)
            decipher = AES.new(key, AES.MODE_ECB)
            encrypted_data = decipher.decrypt(decripted_data)
            decrypted_text = encrypted_data.decode('utf-8', errors='ignore')
            
            if "End data" in decrypted_text:
                f_result.write(f"{decrypted_text}\n")
                print(f"Пароль: {line.strip()}, Текст: {decrypted_text}")
                found = True
                break

    if found:
        break

print("Готово!")
