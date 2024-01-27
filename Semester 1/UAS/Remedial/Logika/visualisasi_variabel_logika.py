import itertools
from tabulate import tabulate

# input variabel
variables = input("Masukkan variabel dipisah dengan spasi (contoh: 'P Q R'): ").split()

# menghitung semua kemungkinan kombinasi
combinations = list(itertools.product([True, False], repeat=len(variables)))

# menampilkan tabel
table = []
for combo in combinations:
	values = ['B' if item else 'S' for item in list(combo)]
	table.append(values)

print(tabulate(table, variables))
print("total baris : ", len(table))