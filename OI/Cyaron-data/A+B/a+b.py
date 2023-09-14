from cyaron import *
for i in range(1, 11) :
    data = IO(file_prefix = "data/", data_id = i)
    a = randint(1, 1e9)
    b = randint(1, 1e9)
    data.input_writeln(a, b)
    data.output_gen("std.exe")