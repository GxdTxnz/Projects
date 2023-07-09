import nltk
nltk.download('punkt')

# открываем файл с байтовыми строками
with open('result.bin', 'rb') as file:
    content = file.read()

# преобразование байтовых строк в текстовые строки
text = content.decode('utf-8')

# токенизация текста с использованием nltk
sentences = nltk.sent_tokenize(text)

# список английских слов
english_words = set(nltk.corpus.words.words())

# поиск строк с английским текстом
english_sentences = []
for sentence in sentences:
    # приведение к нижнему регистру и токенизация
    words = nltk.word_tokenize(sentence.lower())
    # проверка наличия английских слов в токенизированной строке
    if any(word in english_words for word in words):
        english_sentences.append(sentence)

# вывод строк с английским текстом
for sentence in english_sentences:
    print(sentence)
