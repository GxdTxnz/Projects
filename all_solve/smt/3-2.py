import hashlib
from Crypto.Cipher import AES
import os


def decrypt_text(ciphertext, password, salt, iterations):
    key = hashlib.pbkdf2_hmac('sha1', password, salt, iterations, dklen=16)
    cipher = AES.new(key, AES.MODE_ECB)
    decrypted_text = cipher.decrypt(ciphertext)
    return decrypted_text


def pad_file_to_multiple_of_16(file_path):
    file_size = os.path.getsize(file_path)
    if file_size % 16 != 0:
        padding_size = 16 - (file_size % 16)
        with open(file_path, 'ab') as file:
            file.write(b'\x00' * padding_size)
        print(f'Файл {file_path} дополнен нулями')


pad_file_to_multiple_of_16('output.txt')
with open('output.txt', 'rb') as file:
    ciphertext = file.read()
salt = b'SALT'
password = b'test'
for iterations in range(1, 129):
    decrypted_text = decrypt_text(ciphertext, password, salt, iterations)
    with open(f'Iter/decrypted_text_{iterations}', 'wb') as file:
        file.write(decrypted_text)
print("Готово!")
