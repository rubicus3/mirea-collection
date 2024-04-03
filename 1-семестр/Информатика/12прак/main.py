import random
import signal
from string import ascii_lowercase

# Защита ввода от преднамеренного завершения
signal.signal(signal.SIGTSTP, signal.SIG_IGN)
signal.signal(signal.SIGINT, signal.SIG_IGN)
signal.signal(signal.SIGQUIT, signal.SIG_IGN)


# Функция получения слова из случайных символов латинского алфавита
def get_random_word():
    res = ""
    for i in range(5):
        # Выбираем случайную букву из алфавита и добавляем в конец результирующего слова
        res += ascii_lowercase[random.randint(1, 25)]
    return res


# Функция для ввода значения размера матрицы
def input_size() -> int:
    m = ""
    while True:
        print("Введите число от 2 до 5 - размер матрицы:", end=" ")
        try:
            m = int(input().strip())
            if m < 2 or m > 5:
                print("Число должно быть в диапазоне от 2 до 5")
                continue
            break
        except:
            print("Некорректный ввод")
            continue
    return m


# Функция для ввода типа ввода матрицы
def input_state() -> str:
    state = ""
    while (True):
        print("Выберите метод заполнения матрицы (1 - автоматически, 2 - вручную):", end=" ")
        try:
            state = input().strip()
            if state == "1" or state == "2":
                break
            raise ValueError()
        except:
            print("Некорректный ввод")
            continue
    return state

# Функция для ввода матрицы вручную
def input_matrix(matrix_size: int):
    matrix = []
    print()
    print("Ввод слов длиной 5 в ячейки матрицы."
          " Слова должны состоять из букв латинского алфавита.")
    print()
    for i in range(matrix_size):
        k = []
        for j in range(matrix_size):
            while (True):
                print(f"Введите слово для ячейки матрицы для строки {i + 1} и столбца {j + 1}:", end=" ")
                try:
                    word = input().strip().lower()
                    if len(word) != 5:
                        print("Длина слова не равна 5.")
                        raise ValueError()
                    for letter in word:
                        if letter not in ascii_lowercase:
                            print("Слово содержит не только буквы латинского алфавита.")
                            raise ValueError()
                    k.append(word)
                    break
                except:
                    print("Некорректный ввод")
                    continue
        matrix.append(k)
    return matrix


# Функция для автоматического заполнения матрицы случайными словами
def get_random_matrix(matrix_size: int):
    matrix = []
    for i in range(matrix_size):
        k = []
        for j in range(matrix_size):
            word = get_random_word()
            k.append(word)
        matrix.append(k)

    return matrix


# Функция для подсчёта количества гласных и согласных в словах в матрице
def count_letters(matrix: list):
    vowels = "aeyuio" # Возможные гласные
    g = 0 # Счётчик гласных
    t = 0 # Счётчик согласных

    # Цикл по строкам матрицы
    for i in range(len(matrix)):
        # Цикл по словам строки
        for j in range(len(matrix[i])):
            # Цикл по буквам слова в строке
            for l in range(5):
                # Если буква гласная, то увеличиваем счётчик гласных, иначе согласных
                if matrix[i][j][l] in vowels:
                    g += 1
                else:
                    t += 1
    return g, t


# Главная программа
if __name__ == '__main__':
    matrix_size = input_size() # Ввод размера матрицы
    state = input_state() # Ввод типа ввода матрицы

    matrix = []
    if state == "1":
        matrix = get_random_matrix(matrix_size)
    elif state == "2":
        matrix = input_matrix(matrix_size)

    vowels, consonants = count_letters(matrix)

    print("\nИсходная матрица:")
    for i in matrix:
        for j in i:
            print(j, end=" ")
        print()

    print("\nОтсортированная матрица:")
    for i in matrix:
        for j in i:
            print(''.join(sorted(j)), end=" ")
        print()

    print(f"\nГласных: {vowels}")
    print(f"Согласных: {consonants}")
