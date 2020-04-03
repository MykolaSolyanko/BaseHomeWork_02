# якщо імя цього файлу makefile
# запуск можливий наступними командами

# make - зібрати програму
# make run - запустити зібрану програму
# make clean - почистити лишивши тільки джерельні файли

# можна писати в один рядок

# make && make run - зібрати. по закінченню запустити
# make clean && make && make run - почистити. потім зібрати і запустити

#Шаблонний файл
# імʼя компілятора
COMPILER=clang++
# параметри
PARAM=-c -Wall -Wpedantic -std=c++17 -O3
# з яких вайлів збираємо
SOURCES=Taras_Samchuk_HW8.cpp
# формула імен о-файлів
OBJECTS=$(SOURCES:.cpp=.o)
# ім'я програми
EXECUTABLE=Taras_Samchuk_HW8

# скопіпащено початок
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(COMPILER) $(OBJECTS) -o $@

.cpp.o:
	$(COMPILER) $(PARAM) $< -o $@


clean:
	rm -rf *.o $(EXECUTABLE)

# Скопіпащено кінець

# запуск програми
run:
	reset
	./$(EXECUTABLE)

