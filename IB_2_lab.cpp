#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

//ф-я подсчета длины массива
int massLength(char mass[]) {
	int i = 0;
	while (mass[i++]);
	return (i - 1);
}

int main() {
	setlocale(LC_ALL, "Russian");

	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char key[] = "magic"; //ключ
	char word[] = "shifrovanie"; //открытый текст

	//массивы для перевода букв в числовые значения
	int keyNum[100] = { 0 };
	int wordNum[100] = { 0 };
	int wordNumNew[100] = { 0 };

	//переводим массив key в числовое значение
	int l = 0;
	while (l <= massLength(key)) {
		for (int i = 0; i < 25; i++) {
			if (key[l] == alphabet[i])
				keyNum[l] = i;
		}
		l++;
	}

	//переводим массив word в числовое значение
	l = 0;
	while (l <= massLength(word)) {
		for (int i = 0; i < 25; i++) {
			if (word[l] == alphabet[i])
				wordNum[l] = i;
		}
		l++;
	}

	//шифрование
	int p = 0;
	l = 0;
	while (p < massLength(word)) {
		wordNumNew[p] = keyNum[l] + wordNum[p];
		if (wordNumNew[p] > 26)
			wordNumNew[p] -= 26;
		p++;
		l++;
		if (l >= massLength(key))
			l = 0;
	}

	//вывод результата шифрования 
	cout << "Шифр Виженера\n\nИсходный текст: " << word << endl;
	cout << "Ключ: " << key << endl;
	cout << "Результат: ";
	l = 0;
	while (l < massLength(word)) {
		cout << alphabet[wordNumNew[l]];
		l++;
	}
	cout << endl << endl;

	//дешифровка
	p = 0; l = 0;
	int t, m;
	while (p < massLength(word)) {
		t = wordNumNew[p];
		m = keyNum[l];
		t -= m;
		if (t < 0)
			wordNumNew[p] += 26 - keyNum[l];
		else
			wordNumNew[p] -= keyNum[l];
		p++;
		l++;
		if (l >= massLength(key))
			l = 0;
	}

	//вывод результата дешифровки
	cout << "Расшифровка: ";
	l = 0;
	while (l < massLength(word)) {
		cout << alphabet[wordNumNew[l]];
		l++;
	}
	cout << endl;
	return 0;
}