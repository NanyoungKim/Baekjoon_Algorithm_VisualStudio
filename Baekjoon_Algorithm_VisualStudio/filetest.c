#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, fputs, fclose �Լ��� ����� ��� ����

int main()
{
	FILE *fp = fopen("hello.txt", "w");    // hello.txt ������ ���� ���(w)�� ����.
										   // ���� �����͸� ��ȯ
	char arr[30] = "";
	scanf("%[^\n]s", arr);


	fprintf(fp, arr);   // ���Ͽ� ���ڿ� ����

	fclose(fp);    // ���� ������ �ݱ�

	return 0;
}