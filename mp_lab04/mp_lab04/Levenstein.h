#pragma once

// дистанции   Левенштeйна (динамическое программирование)
int levenshtein(
	int lx,           // длина строки x 
	const char x[],   // строка x длинной lx
	int ly,           // длина строки y
	const char y[]    // строка y длинной ly
);

// дистанции   Левенштeйна (рекурсия)
int levenshtein_r(
	int lx,           // длина строки x 
	const char x[],   // строка длиной lx
	int ly,           // длина строки y
	const char y[]    // строка y длинной ly
);
