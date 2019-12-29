#pragma warning(disable: 4996)
#include<ctype.h>
#include <stdio.h>
#include<locale.h>
int main(void)
{
	FILE * f;
	FILE *f_buf;
	char file[20];
	int maxlen = 0;
	char s[1000];
	int opt = 0;
	char opt2 = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите название файла:\n");
	scanf("%s", file, 20);
	printf("Куда вывести? на экран(1) или в файл(2)\n");
	scanf("%d", &opt);
	if (opt == 1)
	{
		int fl = 0, fr = 0, fc = 0, fb = 0;
		f = fopen(file, "rt");
		f_buf = fopen("f_buf.txt", "wt");
		while (fgets(s, 1000, f) != NULL)//форматная обработка конкретной строки
		{
			int f1 = 0;

			for (int i = 0; s[i] != '\0'; i++)
			{
				int t;
				if (s[i] == '%' && s[i + 1] == 'b' && s[i + 2] >= '0' && s[i + 2] <= '9')//задавание начала строки
				{
					t = s[i + 2] - '0';
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					for (int k = 0; k < t; k++)
						fprintf(f_buf, " ");
				}
				if (s[i] == '%' && s[i + 1] == 'e' && s[i + 2] >= '0' && s[i + 2] <= '9')//задавание конца строки
				{
					t = s[i + 2] - '0';
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					s[t] = '\n';
					s[t + 1] = '\0';
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'r')//выравнивание по левому краю всего файла поиск %fr
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fr = 1;
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'l')//выравнивание по правому краю всего файла поиск %fl
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fl = 1;
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'c')//выравнивание по правому краю всего файла поиск %fс
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fc = 1;
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'b')//выравнивание по правому краю всего файла поиск %fb
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fb = 1;
				}

			}
			fprintf(f_buf, "%s", s);
		}
		fclose(f);
		fclose(f_buf);
		if (fb == 1)
		{
			int maxlen = 0;
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				maxlen = (maxlen < i) ? i : maxlen;
			}
			fclose(f_buf);
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int count_of_space = 0;
				int leng = 0;
				for (leng = 0; s[leng] != '\0'; leng++);
				count_of_space = maxlen - leng;
				while (count_of_space > 0)
				{
					for (int k = 0; s[k] != '\0'; k++)
					{
						if ((s[k] == ' ' || s[k] == ',' || s[k] == '.') && maxlen - leng != 0 && (s[k + 1] != '\n'))
						{
							int j;
							for (j = leng; j != k; j--)
								s[j + 1] = s[j];
							leng++;
							s[k + 1] = ' ';
							k++;
							s[leng] = '\0';
							count_of_space--;
						}
					}
				}
				printf("%s", s);
			}
			fclose(f_buf);
		}
		if (fc == 1)//выравнивание по правому краю
		{
			int maxlen = 0;
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				maxlen = (maxlen < i) ? i : maxlen;
			}
			fclose(f_buf);
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				if (i < maxlen)
				{
					for (int k = 0; k < (maxlen - i) / 2; k++)
						printf(" ");
					printf("%s", s);
				}
				else printf("%s", s);
			}
			fclose(f_buf);
		}
		if (fl == 1)//процедура выравнивания файла по левому краю
		{
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i = 0;
				for (i = 0; isalpha(s[i]) == 0; i++);
				for (int k = 0; s[k] != '\0'; k++)
					s[k] = s[k + i];
				printf("%s", s);
			}
			fclose(f_buf);

		}
		if (fr == 1)//процедура выравнивания файла по правому краю
		{
			int maxlen = 0;
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				maxlen = (maxlen < i) ? i : maxlen;
			}
			fclose(f_buf);
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				if (i < maxlen)
				{
					for (int k = 0; k < maxlen - i; k++)
						printf(" ");
					printf("%s", s);
				}
				else printf("%s", s);
			}
			fclose(f_buf);

		}
		fclose(f_buf);
		if (fl == 0 && fr == 0 && fc == 0 && fb == 0)
		{
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
				printf("%s", s);
			fclose(f_buf);
		}
		fl = fr = fc = fb = 0;
		remove("f_buf.txt");
	}
	else if (opt == 2)
	{
		FILE* fi;
		char file_i[20];
		int fl = 0, fr = 0, fc = 0, fb = 0;
		printf("Введите название файла, в который хотите получить результат работы программы:\n");
		scanf("%s", file_i, 20);
		fi = fopen(file_i, "wt");


		f = fopen(file, "rt");
		f_buf = fopen("f_buf.txt", "wt");
		while (fgets(s, 1000, f) != NULL)//форматная обработка конкретной строки
		{
			int f1 = 0;

			for (int i = 0; s[i] != '\0'; i++)
			{
				int t;
				if (s[i] == '%' && s[i + 1] == 'b' && s[i + 2] >= '0' && s[i + 2] <= '9')//задавание начала строки
				{
					t = s[i + 2] - '0';
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					for (int k = 0; k < t; k++)
						fprintf(f_buf, " ");
				}
				if (s[i] == '%' && s[i + 1] == 'e' && s[i + 2] >= '0' && s[i + 2] <= '9')//задавание конца строки
				{
					t = s[i + 2] - '0';
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					s[t] = '\n';
					s[t + 1] = '\0';
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'r')//выравнивание по левому краю всего файла поиск %fr
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fr = 1;
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'l')//выравнивание по правому краю всего файла поиск %fl
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fl = 1;
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'c')//выравнивание по правому краю всего файла поиск %fс
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fc = 1;
				}
				if (s[i] == '%' && s[i + 1] == 'f' && s[i + 2] == 'b')//выравнивание по правому краю всего файла поиск %fb
				{
					for (int l = i; s[l] != '\0'; l++)
						s[l] = s[l + 3];
					fb = 1;
				}

			}
			fprintf(f_buf, "%s", s);
		}
		fclose(f);
		fclose(f_buf);
		if (fb == 1)
		{
			int maxlen = 0;
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				maxlen = (maxlen < i) ? i : maxlen;
			}
			fclose(f_buf);
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int count_of_space = 0;
				int leng = 0;
				for (leng = 0; s[leng] != '\0'; leng++);
				count_of_space = maxlen - leng;
				while (count_of_space > 0)
				{
					for (int k = 0; s[k] != '\0'; k++)
					{
						if ((s[k] == ' ' || s[k] == ',' || s[k] == '.') && maxlen - leng != 0 && (s[k + 1] != '\n'))
						{
							int j;
							for (j = leng; j != k; j--)
								s[j + 1] = s[j];
							leng++;
							s[k + 1] = ' ';
							k++;
							s[leng] = '\0';
							count_of_space--;
						}
					}
				}
				fprintf(fi, "%s", s);
			}
			fclose(f_buf);
		}
		if (fc == 1)//выравнивание по правому краю
		{
			int maxlen = 0;
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				maxlen = (maxlen < i) ? i : maxlen;
			}
			fclose(f_buf);
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				if (i < maxlen)
				{
					for (int k = 0; k < (maxlen - i) / 2; k++)
						fprintf(fi, " ");
					fprintf(fi, "%s", s);
				}
				else fprintf(fi, "%s", s);
			}
			fclose(f_buf);
		}
		if (fl == 1)//процедура выравнивания файла по левому краю
		{
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i = 0;
				for (i = 0; isalpha(s[i]) == 0; i++);
				for (int k = 0; s[k] != '\0'; k++)
					s[k] = s[k + i];
				fprintf(fi, "%s", s);
			}
			fclose(f_buf);

		}
		if (fr == 1)//процедура выравнивания файла по правому краю
		{
			int maxlen = 0;
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				maxlen = (maxlen < i) ? i : maxlen;
			}
			fclose(f_buf);
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
			{
				int i;
				for (i = 0; s[i] != '\0'; i++);
				if (i < maxlen)
				{
					for (int k = 0; k < maxlen - i; k++)
						fprintf(fi, " ");
					fprintf(fi, "%s", s);
				}
				else fprintf(fi, "%s", s);
			}
			fclose(f_buf);

		}
		fclose(f_buf);
		if (fl == 0 && fr == 0 && fc == 0 && fb == 0)
		{
			f_buf = fopen("f_buf.txt", "rt");
			while (fgets(s, 1000, f_buf) != NULL)
				fprintf(fi, "%s", s);
			fclose(f_buf);
		}
		fl = fr = fc = fb = 0;
		remove("f_buf.txt");
		printf("Запись завершена.\n");
		fclose(fi);
	}
	else printf("Неккоректный ввод.Выход из программы.");
	getchar();
	getchar();
}
