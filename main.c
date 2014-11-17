#include <stdio.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

int checkAnagrams(char * str1, char * str2);	/*두 문자열의 아나그램 여부를 리턴해주는 함수*/
int setContinuance();							/*프로그램을 계속할지 결정하는 함수*/

// 프로그램 시작
int main()
{
	char buf1[BUFSIZ];
	char buf2[BUFSIZ];

	do
	{
		// 첫번 째 문자열 입력
		fputs("Input the 1st sentence : ", stdout);
		fgets(buf1, BUFSIZ, stdin);

		// 두번 째 문자열 입력
		fputs("Input the 2nd sentence : ", stdout);
		fgets(buf2, BUFSIZ, stdin);

		// 두 문자열을 비교하여 아나그램인지 아닌지 출력한다.
		if (checkAnagrams(buf1, buf2))
			puts("Yes! They are anagrams!!");
		else
			puts("No! They are not anagrams!!");

	} while (setContinuance());		/*계속할지 결정한다.*/

	puts("Thank you!!");
	return 0;
}

// 프로그램을 계속 할지 결정한다.
int setContinuance()
{
	char buf[BUFSIZ];
	int result;

	while (1)
	{
		fputs("Continue? (y/N) : ", stdout);
		fgets(buf, BUFSIZ, stdin);

		// 입력이 "y\n" 또는 "Y\n"인 경우
		if ((buf[0] == 'y' || buf[0] == 'Y') && strlen(buf) == 2)
		{
			result = TRUE;
			break;
		}

		// 입력이 "n\n" 또는 "N\n"인 경우
		if ((buf[0] == 'n' || buf[0] == 'N') && strlen(buf) == 2)
		{
			result = FALSE;
			break;
		}
	}

	puts("");
	return result;
}

// 두 문자열이 아나그램인지 체크한다.
int checkAnagrams(char * str1, char * str2)
{
	int usedAlphabet['Z' - 'A' + 1] = { 0, };	/*알파벳 개수 만큼 배열을 할당하고 0으로 초기화한다.*/
	int i = 0;
	int result;

	// 첫번째 문자열에 쓰인 알파벳 개수를 카운트한다.
	while (str1[i] != '\0')
	{
		// Case 1 : 대문자인 경우
		if (str1[i] >= 'A' && str1[i] <= 'Z')
			usedAlphabet[str1[i] - 'A']++;

		// Case 2: 소문자인 경우
		else if (str1[i] >= 'a' && str1[i] <= 'z')
			usedAlphabet[str1[i] - 'a']++;

		i++;
	}

	i = 0;	/*인덱스 초기화*/

	// 두번째 문자열에 쓰인 알파벳 개수를 기존 카운트에서 뺀다.
	while (str2[i] != '\0')
	{
		// Case 1 : 대문자인 경우
		if (str2[i] >= 'A' && str2[i] <= 'Z')
			usedAlphabet[str2[i] - 'A']--;

		// Case 2: 소문자인 경우
		else if (str2[i] >= 'a' && str2[i] <= 'z')
			usedAlphabet[str2[i] - 'a']--;

		i++;
	}

	// 체크된 알파벳 카운트를 확인한다. 모두 0이면 두 문자열은 아나그램이다.
	i = 0;
	for (i = 0; i < 'Z' - 'A' + 1; i++)
	{
		// 알파벳 카운트가 0이 아니면 빠져나간다.
		if (usedAlphabet[i] != 0) break;
	}
	
	// Case 1. 중간에 빠져나왔다면 아나그램이 아니다.
	if (i < 'Z' - 'A')
		result = FALSE;
	// 반복문을 끝까지 돌았다면 아나그램이다.
	else
		result = TRUE;

	return result;
}