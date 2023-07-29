# Hanoi_tower

[![GitHub](https://img.shields.io/github/license/BOX-U/Hanoi_tower)](https://github.com/Bunnyspa/GFChipCalc/blob/master/LICENSE)
[![GitHub All Releases](https://img.shields.io/github/downloads/BOX-U/Hanoi_tower/total)](https://github.com/Bunnyspa/GFChipCalc/releases)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/BOX-U/Hanoi_tower)](https://github.com/Bunnyspa/GFChipCalc/releases/latest)
[![GitHub Releases](https://img.shields.io/github/downloads/BOX-U/Hanoi_tower/latest/total)](https://github.com/Bunnyspa/GFChipCalc/releases/latest)

![GitHub watchers](https://img.shields.io/github/watchers/BOX-U/Hanoi_tower?style=social)
![GitHub stars](https://img.shields.io/github/stars/BOX-U/Hanoi_tower?style=social)
![GitHub forks](https://img.shields.io/github/forks/BOX-U/Hanoi_tower?style=social)

재귀하지 않는 하노이탑

하노이 탑의 원판 한번에 하나의 원판만을 움직이는 것
그레이 코드에서 숫자가 1 증가 할 때마다 한자리만 변하는 것을 보고 머릿속에서 떠올라 제작

4개의 디스크를 움직일때 15번 움직여야함 이는 N개의 디스크를 움직일때 2^N-1번의 디스크를 움직여 기둥을 옮길 수있다는 걸로 정의됨
4개의 디스크를 모두 순서대로 임의의 다른 기둥으로 옮길때 

0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000
0    1    2    1    3    1    2    1    4    1    2    1    3    1    2    1              

해당 단계와 전단계를 XOR 연산을 하면 옮겨야 하는 디스크의 번호를 알 수 있고
디스크의 수와 최종 옮길 위치에 따라 처음 옮겨질 디스크의 위치가 달라진다.

각 디스의 움직임 만을 추가로 기록하면

짝수 디스크 최초 1번 핀 최종 3번핀

0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000
0    1    2    1    3    1    2    1    4    1    2    1    3    1    2    1    
-    >    <    >    >    >    <    >    <    >    <    >    >    >    <    >

위를 보면 짝수번째 디스크와 홀 수번째 디스크는 움직는 방향 다르다.
홀수가 1 > 2 > 3 > 1 이런식으로 움직인다면
짝수는 1 > 3 > 2 > 1 이런식으로 움직인다.

위를 기본으로 디스크 수량이 홀 수이면 두경우를 뒤바꾸고
최종위치도 바뀌면 추가로 바뀐다.
