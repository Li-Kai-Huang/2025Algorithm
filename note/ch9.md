# Chapter 9: Medians and Order Statistics (����ƻP���ǲέp�q)

## ���z (Overview)

* **���ǲέp�q (Order Statistics)**�G
    * $n$ �Ӥ������X���� $i$ �p�������٬��� $i$ �Ӷ��ǲέp�q [cite: 90]�C
    * �̤p�ȬO�� 1 �Ӷ��ǲέp�q ($i=1$) [cite: 90]�C
    * �̤j�ȬO�� $n$ �Ӷ��ǲέp�q ($i=n$) [cite: 91]�C
    * **����� (Median)**�G���X���u���I�v [cite: 91]�C
        * �� $n$ ���_�ƮɡA����ƬO�ߤ@���A��� $i=(n+1)/2$ [cite: 91]�C
        * �� $n$ �����ƮɡA����Ӥ���ơG�U����� ($i=\lfloor(n+1)/2\rfloor$) �M�W����� ($i=\lceil(n+1)/2\rceil$) [cite: 91]�C
        * ��ڭ̨ϥΡu����ơv�@���ɡA�q�`�����O�U����� [cite: 91]�C

## ��ܰ��D (The Selection Problem)

* **���D**�G�p��b�@�ӥ]�t $n$ �ӡ]���P�^�Ʀr�����X $A$ ������ $i$ �Ӷ��ǲέp�q�A�䤤 $1 \le i \le n$ [cite: 89]�C
* **��X**�G���X $A$ ����n�j�� $i-1$ �Ө�L���������� $x$ [cite: 90]�C
* ��ܰ��D�i�H�b $O(n \lg n)$ �ɶ����ѨM�G
    * �ϥ� $O(n \lg n)$ �ɶ����t��k�]�p��n�ƧǩΦX�ֱƧǡ^��Ʀr�i��ƧǡC
    * �M���^�Ƨǫ�}�C������ $i$ �Ӥ����C
* �����N���Ф@�ӥi�H�b�w���u�ʮɶ� $O(n)$ ������ $i$ �p�������A�H�Φb�̮t���p�U�� $O(n)$ ���t��k [cite: 89]�C

## �M��̤p�� (Finding Minimum)

* ��� $n$ �Ӥ������X���̤p�Ȫ�²���k�O���N�M���Ҧ����� [cite: 89]�C
* **�t��k**�G
    1.  ��l�� `min` ���}�C���Ĥ@�Ӥ����C
    2.  �q�ĤG�Ӥ����}�l�A�M����l�����C
    3.  �p�G��e�����p�� `min`�A�h��s `min`�C
* **MINIMUM(A) ���X**�G
    ```
    MINIMUM(A)
    1  min �� A[1]
    2  for i �� 2 to length[A]
    3      do if min > A[i]
    4          then min �� A[i]
    5  return min
    ```
* **�ɶ�������**�G�Ӻt��k�i�� $n-1$ ����� [cite: 89]�C
* **�̨Ω�**�G�Ӻt��k�O�̨Ϊ��A�]�����F�̤p�Ȥ��~�A�C�Ӥ����ܤ֥����P�@�Ӹ��p����������@�� [cite: 89]�C
* �άۦP����k�A�N `>` ������ `<` �Y�i���̤j�ȡC

## �P�ɴM��̤p�ȩM�̤j�� (Simultaneous Minimum and Maximum)

* �Y�����ε{���ݭn�P�ɧ��̤p�ȩM�̤j�� [cite: 89]�C
* �W�ߴM��̤p�ȩM�̤j�ȡA�C�ӻݭn $n-1$ ������A�`�@�ݭn $2n-2$ ����� [cite: 89]�C
* **�󦳮Ī���k**�G�̦h�u�ݭn $3\lfloor n/2\rfloor$ ����� [cite: 89]�C
    * ���@��ثe����w�����̤p�ȩM�̤j�ȡC
    * **��l�ȳ]�w**�G
        * �p�G $n$ �����ơA����e��Ӥ����A�N���j���ᵹ `max`�A���p���ᵹ `min`�C�o�˶i�� 1 ������C
        * �p�G $n$ ���_�ơA�N�Ĥ@�Ӥ����P�ɽᵹ `min` �M `max`�C�o�˶i�� 0 ������C
    * **����B�z**�G�q�w�B�z�������]�p�G���^���U�@�Ӥ����}�l�A����B�z�Ѿl�����C
        * ������@�襤����Ӥ����C
        * �M��N���j�������P�ثe���` `max` ����A�N���p�������P�ثe���` `min` ����C
        * �o�˨C�B�z�@�露���ݭn 3 ������C
* **�������**�G
    * �p�G $n$ �����ơG1 (��l) + $3(n-2)/2$ (����B�z) = $1 + 3n/2 - 3 = 3n/2 - 2$ ������C
    * �p�G $n$ ���_�ơG0 (��l) + $3(n-1)/2$ (����B�z) = $3(n-1)/2$ ������C
    * �L�׭��ر��p�A������Ƴ� $\le 3\lfloor n/2\rfloor$ [cite: 89]�C

**�d��**�G
`A = [5, 2, 8, 1, 9, 4, 7, 3]` (n=8, ����)

1.  **��l**�G��� `A[1]=5` �M `A[2]=2`�C
    * `min = 2`, `max = 5` (1 �����)
2.  **����B�z**�G�q `A[3]` �}�l�A�C������Ӥ����C
    * �B�z `(8, 1)`�G`8 > 1`�C
        * `min` �P `1` ����G`2 > 1`�A��s `min = 1`�C
        * `max` �P `8` ����G`5 < 8`�A��s `max = 8`�C (3 �����)
    * �B�z `(9, 4)`�G`9 > 4`�C
        * `min` �P `4` ����G`1 < 4`�A`min` ���ܡC
        * `max` �P `9` ����G`8 < 9`�A��s `max = 9`�C (3 �����)
    * �B�z `(7, 3)`�G`7 > 3`�C
        * `min` �P `3` ����G`1 < 3`�A`min` ���ܡC
        * `max` �P `7` ����G`9 > 7`�A`max` ���ܡC (3 �����)

�`������ơG$1 + 3 + 3 + 3 = 10$ ���C
�ھڤ����G$3n/2 - 2 = 3(8)/2 - 2 = 12 - 2 = 10$ ���C

## �u�ʮɶ�������� (Selection in Expected Linear Time)

* �� $i$ �p��������ܥi�H�b�w���u�ʮɶ������� [cite: 89]�C
* �o�q�`�z�L `RANDOMIZED-SELECT` �t��k�ӹ�{�A�Ӻt��k�O���ֳt�ƧǤ��� `PARTITION` �L�{�C
* **`RANDOMIZED-SELECT(A, p, r, i)` �t��k**�G
    * ��J�G�}�C `A`�A�l�}�C�d�� `[p, r]`�A�n�䪺���ǲέp�q `i`�C
    1.  �p�G `p == r`�A�h��^ `A[p]` (�u�Ѥ@�Ӥ���)�C
    2.  `q = RANDOMIZED-PARTITION(A, p, r)` (�N�}�C��������Ӥl�}�C�A�ê�^��Ǥ��������� `q`)�C
    3.  `k = q - p + 1` (�p���Ǥ����b��e�l�}�C�����ƦW)�C
    4.  �p�G `i == k`�A�h��Ǥ��� `A[q]` �N�O�� $i$ �p�������A��^ `A[q]`�C
    5.  �p�G `i < k`�A�h�� $i$ �p�������b���l�}�C `A[p..q-1]` ���A���j�I�s `RANDOMIZED-SELECT(A, p, q-1, i)`�C
    6.  �p�G `i > k`�A�h�� $i$ �p�������b�k�l�}�C `A[q+1..r]` ���A�B���O�k�l�}�C������ `(i-k)` �p�������A���j�I�s `RANDOMIZED-SELECT(A, q+1, r, i-k)`�C
* **�ɶ�������**�G
    * **�̮t���p**�G�p�G�C�����������ͤ@�Ӥj�p�� $n-1$ ���l���D�A�h�ɶ������׬� $O(n^2)$�C�o������ֳt�ƧǦb�̮t���p�U���欰�C
    * **�̨α��p**�G�p�G�C����������N�}�C��������b�A�h�ɶ������׬� $O(n)$�C���j���Y�� $T(n) = T(n/2) + O(n)$�C
    * **�w���ɶ� (Average Case)**�G$O(n)$�C�ҩ��o�ӻݭn����������v���R�A�����[�W�A�����Ө��A�����|���o�����n�A�ϱo�C�����j���W������Y�p�C

## �̮t���p�u�ʮɶ�������� (Selection in Worst-Case Linear Time)

* �s�b�@�ӧ�������t��k�A�i�H�O�Ҧb�̮t���p�U�]�b $O(n)$ �ɶ������� $i$ �Ӷ��ǲέp�q [cite: 89]�C
* �o�Ӻt��k�٬� `SELECT` (�Ρu����Ƥ�������ơv�t��k)�C
* **`SELECT(A, p, r, i)` �t��k�B�J**�G
    1.  �N��J�� $n$ �Ӥ��������� $\lceil n/5 \rceil$ �ӲաA�C�� 5 �Ӥ����]�̫�@�Ӳեi��֩� 5 �ӡ^�C
    2.  ��C�ժ� 5 �Ӥ����i��Ƨǡ]�Ҧp�A�ϥδ��J�Ƨǡ^�C��X�C�ժ�����ơC
    3.  ���j�a�I�s `SELECT` ��X�o $\lceil n/5 \rceil$ �Ӥ���ƪ������ $x$�C
    4.  �ϥ� $x$ �@����Ǥ����A���J�}�C�i�湺�� `PARTITION(A, p, r, x)`�C���] $x$ �����ެ� $q$�C
    5.  �p�G `i == k` (�䤤 `k` �O $x$ ���ƦW)�A��^ $x$�C
    6.  �p�G `i < k`�A�h���j�a�b���l�}�C���M��� $i$ �p�������C
    7.  �p�G `i > k`�A�h���j�a�b�k�l�}�C���M��� `(i-k)` �p�������C
* **�ɶ�������**�G
    * �B�J 1 �M 2�G$O(n)$ (�C�� 5 �Ӥ����ƧǬO�`�Ʈɶ�)�C
    * �B�J 3�G���j�I�s���W�ҬO $T(\lceil n/5 \rceil)$�C
    * �B�J 4�G�����ާ@�O $O(n)$�C
    * �B�J 5�B6�B7�G���j�I�s���W�ҬO $T(\alpha n)$�C
    * **�����ҩ�**�G�i�H�ҩ��ܤ֦� $3n/10$ �Ӥ����p�� $x$ (�Τj�� $x$)�C�]���A���j�I�s���W�ҳ̦h�� $7n/10$�C
    * ���j���Y�� $T(n) \le T(n/5) + T(7n/10) + O(n)$�C
    * �Ѧ����j���Y�i�o $T(n) = O(n)$�C
* **�u�I**�G�O�ҳ̮t���p�ɶ������׬� $O(n)$�C
* **���I**�G������Τ��A�]���`�Ʀ]�l���j�A�q�` `RANDOMIZED-SELECT` ��{��n�C