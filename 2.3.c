#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>


int GetOut (void){
		int Restart;
		while(!scanf("%d", &Restart)){
			 while(getchar() != '\n');
				printf("������\n");
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
		printf("����� ����������.\n");
		printf("����� ������ ������� 403 ������, 6 �������, 2 �����������.\n");
		printf("������� 1, ���� ������ ���� ������� ����� ");
		userChoice = GetOut();
		if(userChoice != 1){
			printf("����������� ������");
			for (count = 0; count < row; count++){
				printf("\n");
				for(secondCount = 0; secondCount < column; secondCount++){
						z[count][secondCount] = GetRandomNumber();
						printf("%d ", z[count][secondCount]);
				}
			}
		}
		else{
			printf("������� ����������� ������, ��������� �� %d �����\n", row*column);
			for (count = 0; count < row; count++){
				for(secondCount = 0; secondCount < column; secondCount++){
						z[count][secondCount] = GetOut();
				}
			}
			printf("�������� ������\n");
			for (count = 0; count < row; count++){
				for(secondCount = 0; secondCount < column; secondCount++){
						printf("%d ", z[count][secondCount]);
				}
			printf("\n");
			}
		}
		printf("\n");
		printf("������� �����, ������� ����� �������� ����� 0 � ��������� �������\n");
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
		printf("��������� ������");
		for (count = 0; count < row; count++){
				printf("\n");
				for(secondCount = 0; secondCount < column; secondCount++){
						printf("%d ", z[count][secondCount]);
				}
		}
		printf("\n");
		printf("��������� �������\n");
		for (count = 0; count < row; count++){
			printf("%d ", z[count][row]);	
		}
		printf("\n");
	printf("������� 0, ���� ������� ���������\n");
	}
 	while (GetOut() != 0);
}
