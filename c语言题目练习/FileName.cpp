#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//�����������ŷţ�����������
//void reverse(char* string)
//{
//	char tmp = *string;
//	int len = strlen(string);
//	*string = *(string+len - 1);
//	*(string+len- 1) = '\0';
//	if (strlen(string + 1) >= 2)
//		reverse(string + 1);
//	* (string+len- 1) = tmp;
//
//}
//int main()
//{
//	char arr[] = "abcdefgh";
//	reverse(arr);
//	printf("%s", arr);
//	return 0;
//}
// �����������ŷţ��ݹ��㷨��
//void fun(char arr[], int left, int right)
//{
//	if(left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		fun(arr , left+1, right-1);
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdefg";
//	int left = 0;
//	int right = 0;
//	right = strlen(arr) - 1;
//	fun(arr, left, right);
//	printf("%s", arr);
//
//	return 0;
//}
//������a�����ݺ�����b�����ݽ���������һ����
//int main()
//{
//	int a[] = { 1,3,5,7 };
//	int b[] = { 2,4,6,8 };
//	int i = 0;
//	int sz = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = a[i];
//		a[i] = b[i];
//		b[i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}
//����һ���������飬������������²���
// ����һ������init��������г�ʼ��
// ����һ������print��������д�ӡ
// ����һ������reverse�����������������
//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i=0;i<sz;i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void resever(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);//1,2,3,4,5
//	resever(arr, sz);//5,4,3,2,1
//	print(arr, sz);
//	init(arr, sz);//0,0,0,0,0
//	print(arr, sz);
//	return 0;
//}

////��һ�������洢���ڴ��ж�������һ�ĸ���
////��������ĸ���
////int main()
////{
////	int a = 0;
////	scanf("%d", &a);
////	int ret = 0;
////	int i = 0;
////	for(i=0;i<32;i++)
////	{
////		if (((a>>i)&1)==1)
////		{
////			ret++;
////		}
////	}
////	printf("%d \n", ret);
////	return 0;
////}
////�Ƚ��������Ķ����ƣ���ͬ��λ�ж��٣������
////int main()
////{
////	int m = 0, n = 0;
////	int ret = 0;
////	scanf("%d %d", &m, &n);
////	int i = 0;
////	int count = 0;
////	//�������ķ�������ͬΪ0����ͬΪ1
////	ret = m ^ n;
////	for (i = 0; i < 32; i++)
////	{
////		if (((ret >> i)&1) == 1)
////		{
////			count++;
////		}
////		printf("%d", count);
////	}
////	return 0;
////}
////int main()
////{
////	int m = 0, n = 0;
////	int i = 0;
////	int ret = 0;
////	scanf("%d %d", &m, &n);
////	for (i = 0; i < 32; i++)
////	{
////		if (((m >> i) & 1) != ((n >> i) & 1))
////		{
////			ret++;
////		}
////	}
////	printf("%d", ret);
////	return 0;
////}
////����һ�����֣��ֱ��ӡ�����Ƶ�����λ��ż��λ
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	//��ߵ�����λ��31λ������Ҫ�ƶ�15��
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//	printf("\n");
//	//���ż��λ��32���ƶ�15��
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", ((n >> i) & 1));
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0x654321;
//	char   b = (char)a;
//	printf("%d", a);
//	printf("\n%p\n", &a);
//	printf("%0x\n", b);
//}
//ʹ��ָ���ӡһ����������
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	return 0;
//}
//дһ��������ʵ���ַ�������
//#include<string.h>
//void is_nixu(char* p, int left, int right)
//{
//	char ret = 0;
//	while (left < right)
//	{
//		ret = *(p + left);
//		*(p+left) = *(p+right);
//		*(p + right) = ret;
//		left++;
//		right--;
//	}	
//}
//int main()
//{
//	char arr[] = {"abcdefg"};
//	int left = 0;
//	int right = strlen(arr) - 1;
//	is_nixu(arr, left, right);
//	printf("%s ", arr);
//	return 0;
//}
//���õݹ�ķ���
//void is_arr(char* p, int left, int right)
//{
//	char ret = 0;
//	ret = *(p + left);
//	*(p + left) = *(p + right);
//	*(p + right) = ret;
//	left++;
//	right--;
//	if (left < right)
//	{
//		is_arr(p+1,left, right);
//	}
//}
//int mian()
//{
//	char arr[] = { "abcdefg" };
//	int left = 0;
//	int right = strlen(arr) - 1;
//	is_arr(arr, left, right);
//	return 0;
//}
//��sn=a+aa+aaa+aaaa+aaaaa...ǰn��ĺ�
//*int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sn = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sn += ret;
//	}
//	printf("%d ", sn);
//	return *
//}
//��һ��1��10000֮���ˮ�ɻ���
//����153=1^3+5^3+5^3����nλ����n�η��ĺ�
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10001; i++)
//	{
//		//�ж�i�м�λ��
//		int a = 0;
//		int ret =i;
//		int sum = 0;
//		while (ret)
//		{
//			a++;
//			ret /= 10;
//		}
//		//�õ�i��ÿһλ
//		// 1234��
//		//����nλ���ĺ�
//		ret = i;
//		while (ret)
//		{
//			sum += pow((ret  % 10), a);
//			ret /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//����ˮ���⣬һƿ��ˮһԪǮ��������ƿ���Ի�һƿ��ˮ����20��Ǯ���Ժȶ�����ˮ
//int is_qishui(int n)
//{
//	int ret = 0;
//	while(n>=2)
//	{
//		ret++;
//		n--;
//
//	}
//	return ret;
//
//}
//int main()
//{
//	int n = 20;
//	int tmp=is_qishui(n);
//	printf("%d", tmp + 20);
//	return 0;
//}
//int main()
//{
//	double x = 2;
//	double y = x + 3.0 / 2;
//	double z = x + 3 / 2;
//	printf("%lf %lf %lf", x, y, z);
//	return 0;
//
//}
//������������С������,�����
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = (a > b ? a : b);
//	while (1)
//	{
//		if (ret%a == 0 && ret % b == 0)
//		{
//			printf("%d ", ret);
//			break;
//		}
//		ret++;
//	}
//	return 0;
//}
//���Ž�
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int i = 1;
//	while ((a*i)%b)
//	{
//		i++;
//	}
//	printf("%d ", a * i);
//	return 0;
//}
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
//1�������ַ������� 2�ٽ�ÿ����������
// #include <stdio.h>
//#include <string.h>
//
//void ReverseString(char* left, char* right)//��ת�ַ���
//{
//    while (left < right)
//    {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//int main()
//{
//    char str[100] = "0";
//    gets_s(str);
//    int length = strlen(str);
//    ���ַ������巭ת
//    ReverseString(str, str + length - 1);
//    char* start = str;
//    ���ַ����е�ÿ�����ʷ�ת
//    while (*start)
//    {
//        char* end = start;
//        while (*end != ' ' && *end)//Ѱ�ҿո��'\0'
//        {
//            end++;
//        }
//        ReverseString(start, end - 1);
//        if (*end == ' ')
//        {
//            start = end + 1;
//        }
//        else
//        {
//            start = end;
//        }
//    }
//    printf("%s", str);
//    return 0;
//}
//#include<string.h>
//void is_nixu(char* left, char* right)
//{
//	char ret = 0;
//	while (left < right)
//	{
//		ret = *left;
//		*(left) = *(right);
//		*right = ret;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	gets_s(arr);
//	int len = strlen(arr);
//	char* left =arr;
//	char* right = &arr[len - 1];
//	is_nixu(arr, arr+len-1);
//	//printf("%s ", arr);
//	char* end = left;
//	while (*left != '\0')
//	{
//		while (*end != ' ' && *end != '\0')
//		{
//			end++;
//		}
//
//		is_nixu(left, end);
//		left =end+1;
//	}
//	printf("%s ", arr);
//	return 0;
//}
//��дһ������,�����ǰ�һ��char��ɵ��ַ���ѭ������n��������ԭ���ǡ�abcdefghi���n=2
//��λ��Ӧ����"hiabcdefgh��
//#include<string.h>

//int main()
//{
//	char arr[] = { 0 };
//	gets_s(arr);
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	int j = 0;
//	int len = (strlen(arr) - 1);
//	for (i = 0;i<n; i++)
//	{
//		char ret = arr[len];
//		for (j = len; j >0; j--)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[0] = ret;
//	}
//	printf("%s ", arr);
//
//	return 0;
//}
//ģ��ʵ��strlen�����Ĺ���
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr)
//	{
//		arr++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[10] = { 0 };
//	gets_s(arr);
//	int ret = my_strlen(arr);
//	printf("%d ", ret);
//	return 0;
//}
//ģ��ʵ��strcopy��������
//void my_strcpy(char* a,char* b)
//{
//	while(*a!='\0'||*b!='\0')
//	char ret = 0;
//	*a = *b;
//	a++;
//	b++;
//
//}
//int main()
//{
//	char a[5] = {0};
//	char b[5] = { 0 };
//	gets_s(a);
//	gets_s(b);
//	my_strcpy(a, b);
//	printf("%s\n%s", a, b);
//	return 0;
//}
////��������ż��λ�ã�ʹ�������е�������λ��ż��ǰ��
//void is_arr_enve(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	//����������ż���������������������н���
//	while (left < right)
//	{
//		//����ż��ͣ����
//		while ((left < right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//��������ͣ����
//		while ((left < right) && (arr[right] % 2 == 0))
//		{
//			right++;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right++;
//		}
//	}
//}
//int main()
//{
//	//����
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//����
//	is_arr_enve(arr, sz);
//	//���
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int arr2[10] = { 0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < sz; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i < sz; i++)
//    {
//        if (arr[i] % 2 == 1)
//        {
//            arr2[j] = arr[i];
//            j++;
//        }
//    }
//    for (i = 0; i < sz; i++)
//    {
//        if (arr[i] % 2 == 0)
//        {
//            arr2[j] = arr[i];
//            j++;
//        }
//    }
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr2[i]);
//    }
//    return 0;
//}
//���ú���ָ�����ð������
//#include<stdlib.h>
//int cmp_int(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//int main()
//{
//	int arr[10] = {0};
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d",&arr[i]);
//	}
//	int (*pf)(const void*, const void*) = &cmp_int;
////qsort��������Ϊ��Ԫ�أ�Ԫ�ظ�����Ԫ����ռ�ֽڴ�С,�ȽϺ�����int cmp��const void* ,const void*))
//	qsort(arr, sz, sizeof(arr[0]),pf);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
/*void is_nixu(char* s, int left, int right)
{
    while (left < right)
    {
        char tmp = *(s + left);
        *(s + left) = *(s + right);
        *(s + right) = tmp;
        left++;
        right--;
    }
}
char* trans(char* s, int n) {
    int left = 0;
    int right = n - 1;
    int ret = left;
    is_nixu(s, left, right);
    while (*(s + ret))
    {
        ret = left;
        while (*(s + ret) != ' ' && *(s + ret) != '\0' && ret < right)
        {
            ret++;
        }
        is_nixu(s, left, ret - 1);
        left = ret + 1;
    }
    while (left <= right)
    {
        if (*(s + left) >= 'a' && *(s + left) <= 'z')
        {
            *(s + left) -= 32;
        }
        else if (*(s + left) <= 'Z' && *(s + left) >= 'A')
        {
            *(s + left) += 32;
        }
        left++;
    }
    return s;
}
int main()
{
    char s = "hello world"
    int n = 12;
    trans(s, n);
        printf("%s", s);
    return */
////����һ������Ϊ n �ַ�����������Ҫ������һЩ���Ρ�
////��������ַ����а�����һЩ�ո񣬾���"Hello World"һ����Ȼ������Ҫ�����ǰ�����ַ������ɿո����
//// �ĵ��ʷ���ͬʱ��תÿ���ַ��Ĵ�Сд������"Hello World"���κ�ͱ����"wORLD hELLO"
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param s string�ַ���
// * @param n int����
// * @return string�ַ���
// */
//void is_nixu(char* s, int left, int right)
//{
//    while (left < right)
//    {
//        char tmp = *(s + left);
//        *(s + left) = *(s + right);
//        *(s + right) = tmp;
//        left++;
//        right--;
//    }
//}
//char* trans(char* s, int n) {
//    int left = 0;
//    int right = n - 1;
//    int ret = 0;
//    is_nixu(s, left, right);
//    while (left < n)
//    {
//        ret = left;
//        while (*(s + ret) != ' ' && ret < n)
//        {
//            if (*(s + ret) <= 'z' && *(s + ret) >= 'a')
//            {
//                *(s + ret) -= 32;
//            }
//            else if (*(s + ret) >= 'A' && *(s + ret) <= 'Z')
//            {
//                *(s + ret) += 32;
//            }
//            ret++;
//        }
//        is_nixu(s, left, ret - 1);
//        left = ret + 1;
//    }
//    return s;
//}
//ģ��ʵ��strcpy��������
#include<assert.h>
//char* my_strcpy(char* arr2, const char* arr1)
//{
//    assert(arr2);
//    assert(arr1);
//    char* ret = arr2;
//    while (*arr2++ = *arr1++)//����ֵ\0�����ж�
//    {
//      ;
//    }
//    return ret;
//}
// int main()
// {
//        char arr1[] = "abcdefg";
//        char arr2[20] = { 0 };
//        my_strcpy(arr2, arr1);
//        printf("%s ", arr2);
//        return 0;
//}
//ģ��ʵ��strcat��������
//char* my_strcat(char* arr1, const char* arr)
//{
//    assert(arr1 && arr);
//    char* ret = arr1;
//    while((*arr1))
//    {
//        arr1++;
//    }
//    while (*arr1++ = *arr++)
//    {
//        ;
//    }
//    return ret;
//}
//int main()
//{
//    char arr1[20] = "hello ";
//    my_strcat(arr1, "wolrd");
//    printf("%s\n", arr1);
//    return 0;
//}
//ģ��ʵ��strcmp��������
//int my_strcmp(const char* arr1,const char* arr2)
//{
//    assert(arr1 && arr2);
//    while (*arr1 == *arr2)
//    {
//        if (*arr1 == '\0')
//        {
//            return 0;
//        }
//        arr1++;
//        arr2++;
//    }
//    return (*arr1 - *arr2);
//}
//int main()
//{
//    char arr1[] = "abcddf";
//    char arr2[] = "abccccf";
//    int ret = my_strcmp(arr1, arr2);
//    if (ret > 0)
//    {
//        printf("arr1>arr2");
//    }
//    else if (ret < 0)
//    {
//        printf("arr1<arr2");
//    }
//    else
//    {
//        printf("arr1==arr2");
//    }
//    return 0;
//}
//ģ��ʵ��strstr��������
#include<assert.h>
//char* my_strstr(const char* arr1, const char* arr2)
//{
//    assert(arr1 && arr2);
//    const char* p =  arr1;//��ס��ʼ�ҵ���ʼλ��
//    const char* s1 = arr1;//���ñ��ҵı���
//    const char* s2 = arr2;//�����ҵı���
//    while (*p)
//    {
//        s1 = p;
//        s2 = arr2;
//        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//        {
//            s1++;
//            s2++;
//        }
//        if (*s2 == '\0')
//        {
//            return (char*)p;
//        }
//        p++;
//    }
//    return NULL;
//
//}
//int main()
//{
//    char arr1[] = "abbbcef";
//    char arr2[] = "bbc";
//    char* ret = my_strstr(arr1, arr2);
//    if (ret == NULL)
//    {
//        printf("û�ҵ�\n");
//    }
//    else
//        printf("%s ", ret);
//    return 0;
//}
//ģ��ʵ��memcpy��������
//void* my_memcpy(void* arr2, const void* arr1, size_t num)
//{
//    assert(arr2 && arr1);
//    void* ret = arr2;
//    while (num--)
//    {
//        *(char*)arr2 = *(char*)arr1;
//       arr2=(char*)arr2+1;
//        arr1=(char*)arr1+1;
//    }
//    return ret;
//}
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6,7 };
//    int arr2[10] = { 0 };
//    my_memcpy(arr2, arr1, 28);
//   
//    return 0;
//}
//ģ��ʵ��memmove��������
//void* my_memmove(void* arr2, const void* arr1, size_t num)
//{
//    assert(arr2 && arr1);
//    void* ret = arr2;
//    if (arr2 < arr1)
//    {
//        //��������ʼλ��С�ڿ�����ʼλ��
//        //��ǰ���󿽱�
//        while (num--)
//        {
//            *(char*)arr2 = *(char*)arr1;
//            arr2 = (char*)arr2 + 1;
//            arr1 = (char*)arr1 + 1;
//        }
//    }
//    else
//    {
//        //��������ʼλ�ô��ڿ�����ʼλ��
//        //�Ӻ���ǰ����
//        while (num--)
//        {
//            *((char*)arr2 + num) = *((char*)arr1 + num);
//        }
//    }
//    return ret;
//}
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//  /*  int arr2[10] = { 0 };*/
//    my_memmove(arr1, arr1+2, 20);
//    for (int i = 0; i < 10; i++ )
//    {
//        printf("%d ",arr1[i]);
//    }
//    return 0;
//}
//�ַ�������
//ʵ��һ�����������������ַ����е�k���ַ�
//void is_zuoxuan(char* arr, int k,int sz)
//{
//    int i = 0;
//    int j = 0;
//    k %= sz;
//    for (i = 0; i < k; i++)
//    {
//        char ret =*arr;
//        for (j = 0; j<sz-1; j++)
//        {
//         *(arr + j) = *(arr + j + 1);
//        }
//        *(arr+sz-1) = ret;
//    }
//}
//int main()
//{
//    int k = 0;
//    char arr[10] ="abcdef";
//    scanf("%d", &k);
//    int sz = strlen(arr);
//    is_zuoxuan(arr, k,sz);
//    printf("%s ", arr);
//    return 0;
//}
//���Ͼ���
//�ھ������ҵ������k��ֵ���������±�
//��Ϊ���Ͼ�����ÿ�д����ҵ�����ÿ�д��ϵ��µ��������Ը���һ�����ı�
//2��������ͨ���ṹ����з����±�
//int is_find(int arr[3][3], int* pa, int* pb, int k)
//{
//    int x = 0;
//    int y = *pb - 1;
//    while (x <= 2 && y >= 0)
//    {
//        if (k < arr[x][y])
//        {
//            y--;
//        }
//        else if (k > arr[x][y])
//        {
//            x++;
//        }
//        else
//        {
//            *pa = x;//ͨ����ַ�ı��±�
//            *pb = y;//
//            return 1;
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//    int a = 3;
//    int b = 3;
//    int k = 0;
//    scanf("%d", &k);
//    int ret=is_find(arr, &a, &b, k);
//    if (ret == 1)
//    {
//        printf("�ҵ���,�±�Ϊ %d %d\n", a, b);
//    }
//    else
//    {
//        printf("û�ҵ�");
//    }
//
//    return 0;
//}
//ʵ��qsort�����Ĺ���,�ж�����ĺ���
#include<stdlib.h>
int cmp_int(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e);
}
int main()
{
    int arr[10] = { 0 };
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort((void*)arr, sz, sizeof(arr[0]),cmp_int);
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }


    return 0;
}