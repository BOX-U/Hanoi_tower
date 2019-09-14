#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_gray(int integer);
void hanoi_loop(int n);


//�ϳ��� ž�� ��������̸鼭 ������ ���� �ʴ� ������� ǰ
void main(){
	int num;

	printf_s("���� �� �Է�");
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
		diskmovenum = (int)log2(get_gray(i) ^ get_gray(i - 1)) + 1;//���� �������� ��ũ ��ȣ
		printf("%5d : ",i);
		for(j=0;j<diskmovenum;++j)
			printf("#");
		printf("%d��° ��ũ�� %c����", diskmovenum, movepoint[disk[diskmovenum]]);

		if ((n & 1) ^ (diskmovenum & 1))//�ű� ��ũ ��ȣ ��ü ��ũ ���� ���� ������ �޶���
			disk[diskmovenum] = (disk[diskmovenum] + 1) % 3;//����
		else
			disk[diskmovenum] = (disk[diskmovenum] + 2) % 3;//�� 3�� �̱� ������ 2�� ���ϸ� �������� ������ ����
		printf("%c�� �̵�\n", movepoint[disk[diskmovenum]]);
	}
	return;
}

int get_gray(int integer)//�׷��� �ڵ� ��� �Լ�
{
	int i;//ī��Ʈ ����
	int n;//�Էµ� ������ �ִ��ڸ���
	int gray = 0;//�߰� ��갪 ����
	int sign = 0;//
	/*
	n = (int)(log(integer) / M_LN2);//�Էµ� ������ �ִ��ڸ���
	for (i = n; i >= 0; --i){
		gray <<= 1;
		if ((((1 << i) & integer)>0) ^ (sign == 1)){//�� �ڸ��� �׷����ڵ带 ���
			++gray;
			sign ^=1;//
		}
	}*/

	gray = (integer & 0x8000000)>0;
	for (i = 31; i >= 1; --i) {
		gray <<= 1;
		if ((((1 << i) & integer) > 0) ^ (((1 << (i-1)) & integer) > 0)) {//�� �ڸ��� �׷����ڵ带 ���
			++gray;
		}
	}

	return gray;
}

