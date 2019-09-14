#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_gray(int integer);
void hanoi_loop(int n);


//하노이 탑을 비재귀적이면서 스택을 쓰지 않는 방법으로 품
void main(){
	int num;

	printf_s("판의 수 입력");
	scanf_s("%d",&num);

	hanoi_loop(num);

	system("pause");

	return;
}

void hanoi_loop(int n){
	char movepoint[3] = {"ABC"};
	int i,j;
	int *disk,diskmovenum;
	unsigned long long movenum= (unsigned long long)1 << n;

	disk = (int*)calloc((n + 1),sizeof(int));
	
	for(i=1;i<movenum;++i){
		diskmovenum = (int)log2(get_gray(i) ^ get_gray(i - 1)) + 1;//지금 움직여할 디스크 번호
		printf("%5d : ",i);
		for(j=0;j<diskmovenum;++j)
			printf("#");
		printf("%d번째 디스크를 %c에서", diskmovenum, movepoint[disk[diskmovenum]]);

		if ((n & 1) ^ (diskmovenum & 1))//옮길 디스크 번호 전체 디스크 수에 따라 조건이 달라짐
			disk[diskmovenum] = (disk[diskmovenum] + 1) % 3;//정순
		else
			disk[diskmovenum] = (disk[diskmovenum] + 2) % 3;//총 3개 이기 때문에 2를 더하면 나머지는 역순과 같음
		printf("%c로 이동\n", movepoint[disk[diskmovenum]]);
	}
	return;
}

int get_gray(int integer)//그레이 코드 얻는 함수
{
	int i;//카운트 변수
	int n;//입력된 숫자의 최대자리수
	int gray = 0;//중간 계산값 저장
	int sign = 0;//
	/*
	n = (int)(log(integer) / M_LN2);//입력된 숫자의 최대자리수
	for (i = n; i >= 0; --i){
		gray <<= 1;
		if ((((1 << i) & integer)>0) ^ (sign == 1)){//각 자리의 그레이코드를 계산
			++gray;
			sign ^=1;//
		}
	}*/

	gray = (integer & 0x8000000)>0;
	for (i = 31; i >= 1; --i) {
		gray <<= 1;
		if ((((1 << i) & integer) > 0) ^ (((1 << (i-1)) & integer) > 0)) {//각 자리의 그레이코드를 계산
			++gray;
		}
	}

	return gray;
}

