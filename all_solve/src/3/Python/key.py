import hashlib

password = b'test'
salt = b'SALT'
iterations = 100

key = hashlib.pbkdf2_hmac('sha1', password, salt, iterations, dklen=16)

print(key)
