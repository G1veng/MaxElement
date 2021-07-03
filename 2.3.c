#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>


int GetOut (void){
		int Restart;
		while(!scanf("%d", &Restart)){
			 while(getchar() != '\n');
				printf("Ошибка\n");
		}		
		return Restart;	
}


int GetRandomNumber (void){
	int random;
	random = rand() % 5;
	return random;
}


int main(void){
	int p = 0, count = 0, secondCount = 0, variable = 0, userChoice = 0, column = 6, row = 5;
	int z[row][column];
	setlocale(LC_ALL, "");
	do {
		printf("Добро пожаловать.\n");
		printf("Шишко Даниил Юрьевич 403 группа, 6 вариант, 2 контрольная.\n");
		printf("Введите 1, если хотите сами вводить числа ");
		userChoice = GetOut();
		if(userChoice != 1){
			printf("Изначальный массив");
			for (count = 0; count < row; count++){
				printf("\n");
				for(secondCount = 0; secondCount < column; secondCount++){
						z[count][secondCount] = GetRandomNumber();
						printf("%d ", z[count][secondCount]);
				}
			}
		}
		else{
			printf("Введите изначальный массив, состоящий из %d чисел\n", row*column);
			for (count = 0; count < row; count++){
				for(secondCount = 0; secondCount < column; secondCount++){
						z[count][secondCount] = GetOut();
				}
			}
			printf("Введённый массив\n");
			for (count = 0; count < row; count++){
				for(secondCount = 0; secondCount < column; secondCount++){
						printf("%d ", z[count][secondCount]);
				}
			printf("\n");
			}
		}
		printf("\n");
		printf("Введите число, которое будет заменять собой 0 в последнем столбце\n");
		p = GetOut();
		for (count = 0; count < row; count++){
			for(secondCount = 0; secondCount < column; secondCount++){
				variable = z[count][secondCount];
				z[count][secondCount] = z[count][row];
				z[count][row] = variable;
				if (secondCount == row && z[count][secondCount] == 0){
				z[count][secondCount] = p;
				}
			}
		}
		printf("Изменённый массив");
		for (count = 0; count < row; count++){
				printf("\n");
				for(secondCount = 0; secondCount < column; secondCount++){
						printf("%d ", z[count][secondCount]);
				}
		}
		printf("\n");
		printf("Псоледний столбец\n");
		for (count = 0; count < row; count++){
			printf("%d ", z[count][row]);	
		}
		printf("\n");
	printf("Введите 0, если ихотите закончить\n");
	}
 	while (GetOut() != 0);
}
