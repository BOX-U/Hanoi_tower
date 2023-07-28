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
1    2    1    3    1    2    1    4    1    2    1    3    1    2    1    
