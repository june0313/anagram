#include <stdio.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

int checkAnagrams(char * str1, char * str2);	/*�� ���ڿ��� �Ƴ��׷� ���θ� �������ִ� �Լ�*/
int setContinuance();							/*���α׷��� ������� �����ϴ� �Լ�*/

// ���α׷� ����
int main()
{
	char buf1[BUFSIZ];
	char buf2[BUFSIZ];

	do
	{
		// ù�� ° ���ڿ� �Է�
		fputs("Input the 1st sentence : ", stdout);
		fgets(buf1, BUFSIZ, stdin);

		// �ι� ° ���ڿ� �Է�
		fputs("Input the 2nd sentence : ", stdout);
		fgets(buf2, BUFSIZ, stdin);

		// �� ���ڿ��� ���Ͽ� �Ƴ��׷����� �ƴ��� ����Ѵ�.
		if (checkAnagrams(buf1, buf2))
			puts("Yes! They are anagrams!!");
		else
			puts("No! They are not anagrams!!");

	} while (setContinuance());		/*������� �����Ѵ�.*/

	puts("Thank you!!");
	return 0;
}

// ���α׷��� ��� ���� �����Ѵ�.
int setContinuance()
{
	char buf[BUFSIZ];
	int result;

	while (1)
	{
		fputs("Continue? (y/N) : ", stdout);
		fgets(buf, BUFSIZ, stdin);

		// �Է��� "y\n" �Ǵ� "Y\n"�� ���
		if ((buf[0] == 'y' || buf[0] == 'Y') && strlen(buf) == 2)
		{
			result = TRUE;
			break;
		}

		// �Է��� "n\n" �Ǵ� "N\n"�� ���
		if ((buf[0] == 'n' || buf[0] == 'N') && strlen(buf) == 2)
		{
			result = FALSE;
			break;
		}
	}

	puts("");
	return result;
}

// �� ���ڿ��� �Ƴ��׷����� üũ�Ѵ�.
int checkAnagrams(char * str1, char * str2)
{
	int usedAlphabet['Z' - 'A' + 1] = { 0, };	/*���ĺ� ���� ��ŭ �迭�� �Ҵ��ϰ� 0���� �ʱ�ȭ�Ѵ�.*/
	int i = 0;
	int result;

	// ù��° ���ڿ��� ���� ���ĺ� ������ ī��Ʈ�Ѵ�.
	while (str1[i] != '\0')
	{
		// Case 1 : �빮���� ���
		if (str1[i] >= 'A' && str1[i] <= 'Z')
			usedAlphabet[str1[i] - 'A']++;

		// Case 2: �ҹ����� ���
		else if (str1[i] >= 'a' && str1[i] <= 'z')
			usedAlphabet[str1[i] - 'a']++;

		i++;
	}

	i = 0;	/*�ε��� �ʱ�ȭ*/

	// �ι�° ���ڿ��� ���� ���ĺ� ������ ���� ī��Ʈ���� ����.
	while (str2[i] != '\0')
	{
		// Case 1 : �빮���� ���
		if (str2[i] >= 'A' && str2[i] <= 'Z')
			usedAlphabet[str2[i] - 'A']--;

		// Case 2: �ҹ����� ���
		else if (str2[i] >= 'a' && str2[i] <= 'z')
			usedAlphabet[str2[i] - 'a']--;

		i++;
	}

	// üũ�� ���ĺ� ī��Ʈ�� Ȯ���Ѵ�. ��� 0�̸� �� ���ڿ��� �Ƴ��׷��̴�.
	i = 0;
	for (i = 0; i < 'Z' - 'A' + 1; i++)
	{
		// ���ĺ� ī��Ʈ�� 0�� �ƴϸ� ����������.
		if (usedAlphabet[i] != 0) break;
	}
	
	// Case 1. �߰��� �������Դٸ� �Ƴ��׷��� �ƴϴ�.
	if (i < 'Z' - 'A')
		result = FALSE;
	// �ݺ����� ������ ���Ҵٸ� �Ƴ��׷��̴�.
	else
		result = TRUE;

	return result;
}