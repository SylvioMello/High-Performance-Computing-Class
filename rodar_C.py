import pandas as pd
import os

os.system('gcc test.c -o test')
for i in range(300, 46301, 1000):
    os.system(f'test.exe {i}')

dados = pd.read_csv('pontos_em_C.csv')
print(dados)
