# input()で入力を受け取り、split()でスペース区切りにリスト化する
# map(関数、リスト)で関数をリストの全要素にかける
# 今回は全要素をint型にキャストしている
A, B = map(int, input().split())
# AまたはBが偶数なら'No',どちらも奇数なら'Yes'
if A % 2 is 0 or B % 2 is 0:
    print('No')
else:
    print("Yes")
