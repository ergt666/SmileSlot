#!/bin/bash

# Назва вихідного виконуваного файлу
OUTPUT="my_game"

# Список файлів для компіляції
SOURCES="main.cpp GameLogic.cpp Graphics.cpp -lsfml-audio -lsfml-system"

# Компіляція за допомогою g++
g++ -o $OUTPUT $SOURCES

# Перевірка результату компіляції
if [ $? -eq 0 ]; then
    echo "Компіляція завершена успішно. Виконуваний файл: $OUTPUT"
else
    echo "Помилка під час компіляції."
fi
